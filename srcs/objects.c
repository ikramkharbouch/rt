/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:28:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/14 16:17:19 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_object			*Find_closest(t_camera camera, t_list *objects, int i, int j, t_ray *ray)
{
	t_object		*obj1;
	t_list			*tmp;

	camera = ft_create_cam(camera.eye, camera.look_at, camera.fov);
	*ray = generate_ray(&camera, i, j);
	tmp = objects;
	((t_object *)tmp->content)->t = FALSE;
	while (tmp)
	{
		obj1 = (t_object *)(tmp->content);
		if (!(ft_strcmp(((t_object*)tmp->content)->name, "sphere")))
			((t_object*)tmp->content)->t = sphere(ray,(t_object*)tmp->content);
		else if (!(ft_strcmp(((t_object*)tmp->content)->name, "plane")))
			((t_object*)tmp->content)->t = plane(ray, (t_object*)tmp->content);
		else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cone")))
			((t_object*)tmp->content)->t = cone(ray, (t_object*)tmp->content);
		else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cylinder")))
			((t_object*)tmp->content)->t = cylinder(ray, (t_object*)tmp->content);
		else
			((t_object *)tmp->content)->t = FALSE;
		if (((t_object*)tmp->content)->t * 10000 < obj1->t * 10000)
			obj1 = (t_object *)tmp->content;
		tmp = tmp->next;
	}
	if (obj1->t == FALSE)
		return (NULL);
	return (obj1);
}

void	draw(t_mlx *mlx, t_camera cam,t_list *objects, t_list *lights)
{
	int			i;
	int			j;
	t_object	*obj;
	t_ray 		ray;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			obj = Find_closest(cam, objects, i, j, &ray);
			j++;
			if (obj == NULL)
				continue ;
			ft_mlx_pixel_put(mlx, i, HEIGHT - j - 1, phong_model(obj, &ray, lights));
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void create_actual_objs(t_mlx *mlx, t_camera camera, t_list *lights, t_list *objects)
{
	draw(mlx, camera, objects, lights);
}

