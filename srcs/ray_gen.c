/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:11:08 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 23:29:58 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

// float		get_dist(t_vector eye, t_vector look_at)
// {
// 	float result;
// 	float a;
// 	float b;
// 	float c;

// 	a = pow((look_at.x - eye.x), 2);
// 	b = pow((look_at.y - eye.y), 2);
// 	c = pow((look_at.z - eye.z), 2);
// 	result = sqrtf(a + b + c);
// 	return (result);
// }

// t_camera	ft_create_cam(t_vector eye, t_vector look_at, float fov)
// {
// 	t_camera	camera;
// 	t_vector		up;
// 	float		dist;

// 	dist = get_dist(look_at, eye);
// 	up = (t_vector){0.0, 1.0, 0.0};
// 	camera.fov = DEG_TO_RAD(fov);
// 	camera.eye = eye;
// 	camera.look_at = look_at;
// 	camera.view_dir = vec_normalize(vec_sub(look_at, eye));
// 	camera.u = vec_normalize(vec_cross(camera.view_dir, up));
// 	camera.v = vec_normalize(vec_cross(camera.u, camera.view_dir));
// 	camera.h_height = tan(camera.fov / 2.0) * 2.0 * dist;
// 	camera.aspect_ratio = (float)WIDTH / (float)HEIGHT;
// 	camera.h_width = camera.aspect_ratio * camera.h_height;
// 	camera.bottom_left = vec_sub(camera.look_at,
// 	vec_sum(vec_kscale(camera.h_height, camera.v),
// 	vec_kscale(camera.h_width, camera.u)));
// 	camera.x_incv = vec_kscale(2.0 * camera.h_width, camera.u);
// 	camera.y_incv = vec_kscale(2.0 * camera.h_height, camera.v);
// 	return (camera);
// }

// t_ray		generate_ray(t_camera *camera, int x, int y)
// {
// 	t_ray ray;
// 	t_vector plane_point;

// 	ray.origin = camera->eye;
// 	plane_point = vec_sum(camera->bottom_left,
// 	vec_sum(vec_kscale((float)x / (float)WIDTH,
// 	camera->x_incv), vec_kscale((float)y / (float)HEIGHT, camera->y_incv)));
// 	ray.dir = vec_normalize(vec_sub(plane_point, camera->eye));
// 	return (ray);
// }












































float		get_dist(t_vector eye, t_vector look_at)
{
	float result;
	float a;
	float b;
	float c;

	a = pow((look_at.x - eye.x), 2);
	b = pow((look_at.y - eye.y), 2);
	c = pow((look_at.z - eye.z), 2);
	result = sqrtf(a + b + c);
	return (result);
}

t_camera	ft_create_cam(t_vector eye, t_vector look_at, float fov)
{
	t_camera 	camera;
	t_vector		up;
	float		dist;

	dist 					= get_dist(look_at, eye);
	up 						= (t_vector){0.0, 1.0, 0.0};
	camera.fov 				= DEG_TO_RAD(fov);
	camera.eye 				= eye;
	camera.look_at			= look_at;
	camera.view_dir 		= vec_normalize(vec_sub(look_at, eye));
	camera.u 				= vec_normalize(vec_cross(camera.view_dir, up));
	camera.u 				= vec_kscale(-1,camera.u);
	camera.v 				= vec_normalize(vec_cross(camera.u, camera.view_dir));
	camera.v 				= vec_kscale(-1,camera.v);
	camera.h_height 		= tan(camera.fov / 2.0) * 2.0 * dist;
	camera.aspect_ratio 	= (float)WIDTH / (float)HEIGHT;
	camera.h_width 			= camera.aspect_ratio * camera.h_height;
	return (camera);
}

t_ray generate_ray(t_camera *camera, int i, int j)
{
    t_ray ray;
    float deltax;
    float deltay;
    float x;
    float y;

    ray.origin = camera->eye;
    deltax = camera->h_width / WIDTH;
    deltay = camera->h_height / HEIGHT;
    if (i >= 0 && i <= WIDTH / 2)
        x = -(camera->h_width / 2) + i * deltax;
    if (i > WIDTH / 2)
        x = (i - WIDTH / 2) * deltax;
    if (j >= 0 && j <= HEIGHT / 2)
        y = (camera->h_height / 2) - j * deltay;
    if (j > HEIGHT / 2)
        y = - (j - HEIGHT / 2) * deltay;
    ray.dir = vec_sum(vec_kscale(x, camera->u), vec_kscale(y, camera->v));
    ray.dir = vec_sum(ray.dir, camera->view_dir);
    ray.dir = vec_sum(ray.dir, camera->look_at);
    ray.dir = vec_sum(ray.dir, vec_kscale(-1,ray.origin));
    ray.dir = vec_normalize(ray.dir);
    return(ray);
}
