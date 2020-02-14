/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:40:41 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/14 19:31:35 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** Parse object is not done yet
*/

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

int		get_data(char *filename, t_mlx *mlx)
{
	t_parser	*p;

	if (!(p = parse(filename)))
		return (0);
	if (!check(p))
		return (0);
	Fill(p, mlx); // Fill in the structs
	free_parser(&p);
	return (1);
}