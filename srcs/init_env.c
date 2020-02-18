/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:49:21 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 18:01:44 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	init_cam(t_camera *camera)
{
	camera->eye = (t_vec){0.0, 0.0, 0.0};
	camera->look_at = (t_vec){0.0, 0.0, 0.0};
	camera->fov = 0.0;
	camera->dist = 0.0;
}

void	init_light(t_light *light)
{
	light->origin = (t_vec){0.0, 0.0, 0.0};
	light->dir = (t_vec){0.0, 0.0, 0.0};
	light->intensity = 0.0;
}

void	init_obj(t_object *obj)
{
	obj->name = NULL;
	obj->center = (t_vec){0.0, 0.0, 0.0};
	obj->radius = 0.0;
	obj->ks = 0.0;
	obj->kd = 0.0;
	obj->n = 0.0;
}

void	init_rot(t_rot *rot)
{
	rot->on = 0;
	rot->alpha_x = 0;
	rot->alpha_y = 0;
	rot->alpha_z = 0;
}

void	init_trans(t_trans *trans)
{
	trans->on = 0;
	trans->vec = (t_vec){0.0, 0.0, 0.0};
}
