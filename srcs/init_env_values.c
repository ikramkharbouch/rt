/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:19:00 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/08 17:39:24 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

void    init_mlx_values(t_mlx *mlx)
{
    mlx->mlx_ptr        = NULL;
    mlx->win_ptr        = NULL;
    mlx->img_ptr        = NULL;
    mlx->img_data       = NULL;
    mlx->bits_per_pixel = 0;
    mlx->size_line      = 0;
    mlx->endian         = 0;
    mlx->x              = 0;
    mlx->y              = 0;
}

void    init_camera_values(t_camera *camera)
{
    camera->eye             = (t_vec){0.0, 0.0, 0.0};
    camera->look_at         = (t_vec){0.0, 0.0, 0.0};
    camera->up              = (t_vec){0.0, 0.0, 0.0};
    camera->u               = (t_vec){0.0, 0.0, 0.0};
    camera->v               = (t_vec){0.0, 0.0, 0.0};
    camera->view_dir        = (t_vec){0.0, 0.0, 0.0};
    camera->bottom_left     = (t_vec){0.0, 0.0, 0.0};
    camera->x_incv          = (t_vec){0.0, 0.0, 0.0};
    camera->y_incv          = (t_vec){0.0, 0.0, 0.0};
    camera->aspect_ratio    = 0.0;
    camera->fov             = 0.0;
    camera->h_width         = 0.0;
    camera->h_height        = 0.0;
    camera->dist            = 0.0;
}

void    init_lights_values(t_light *light)
{
    light->dir       = (t_vec){0.0, 0.0, 0.0};
    light->origin    = (t_vec){0.0, 0.0, 0.0};
    light->intensity = 0.0;
}

void    init_objects_values(t_object *object)
{
    object->center  = (t_vec){0.0, 0.0, 0.0};
    object->vec_dir = (t_vec){0.0, 0.0, 0.0};
    object->name    = NULL;
    object->radius  = 0.0;
    object->alpha   = 0.0;
    object->ks      = 0.0;
    object->ks      = 0.0;
    object->n       = 0.0;
    object->t       = 0.0;
    object->color   = 0;
}

void    init_scene_values(t_camera *camera, t_light *light, t_object *object)
{
    init_camera_values(camera);
    init_lights_values(light);
    init_objects_values(object);
}