/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:56:07 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/10 21:25:53 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

float		get_dist(t_point eye, t_point look_at)
{
	float 	result;
	float	a;
	float	b;
	float	c;

	a = pow((look_at.x - eye.x), 2);
	b = pow((look_at.y - eye.y), 2);
	c = pow((look_at.z - eye.z), 2);
	result = sqrtf(a + b + c);
	return (result);
}

void        create_camera(void)
{
    t_camera    *camera;

    camera = &(g_env->scene->camera);
    
    camera->dist = get_dist(camera->eye, camera->look_at);
    camera->up = (t_vec){0.0, 1.0, 0.0};
    camera->fov = DEG_TO_RAD(camera->fov);
    camera->view_dir = vec_normalize(vec_sub(camera->look_at, camera->eye));
    camera->u = vec_normalize(vec_cross(camera->view_dir, camera->up));
    camera->v = vec_normalize(vec_cross(camera->u, camera->view_dir));
    camera->h_height = tan(camera->fov / 2.0) * 2.0 * camera->dist;
    camera->aspect_ratio = (float)WIDTH / (float)HEIGHT;
    camera->h_width = camera->aspect_ratio * camera->h_height;
    camera->bottom_left = vec_sub(camera->look_at, vec_sum(vec_kscale(camera->h_height, camera->v), vec_kscale(camera->h_width, camera->u)));
    camera->x_incv = vec_kscale(2.0 * camera->h_width, camera->u);
    camera->y_incv = vec_kscale(2.0 * camera->h_height, camera->v);

    g_env->scene->camera = *camera;
}

t_ray       ray_gen(int i, int j)
{
    t_ray       ray;
    t_camera    camera;
    float   delta_x, delta_y;
    float   x, y;

    camera = g_env->scene->camera;
    ray.origin = camera.eye;
    delta_x = camera.h_height / HEIGHT;
    delta_y = camera.h_width / WIDTH;
    if (i >= 0 && i <= HEIGHT / 2)
        x = -(camera.h_height / 2) + i * delta_x;
    if (i > HEIGHT / 2)
        x = (i - HEIGHT / 2) * delta_x;
    if (j >= 0 && j <= WIDTH / 2)
        y = -(camera.h_width / 2) - j * delta_y;
    if (j > WIDTH / 2)
        y = -(j - WIDTH / 2) * delta_y;
    ray.dir = vec_normalize(vec_sum(vec_sum(vec_sum(vec_sum(vec_kscale(x, camera.u), 
                vec_kscale(y, camera.v)), camera.view_dir), camera.look_at), vec_kscale(-1, ray.origin)));
    return (ray);
}