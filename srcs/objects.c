/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:28:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/24 15:29:40 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_object	*ramplir(t_camera camera, t_list *objects, int i, int j, t_ray *ray)
{
	t_object		*obj1;
	t_list			*tmp;
	t_object		*object;

	camera = ft_create_cam(camera.eye, camera.look_at, camera.fov);
	*ray = generate_ray(&camera, i, j);
	tmp = objects;
	((t_object *)tmp->content)->t = FAR;
	obj1 = (t_object *)tmp->content;
	while (tmp)
	{
		object = tmp->content;
		if (!(ft_strcmp(object->name, "sphere")))
			object->t = sphere(ray,(t_object*)tmp->content);
		else if (!(ft_strcmp(object->name, "plane")))
			object->t = plane(ray, (t_object*)tmp->content);
		else if (!(ft_strcmp(object->name, "cylinder")))
			object->t = cylinder(ray, (t_object*)tmp->content);
		else if (!(ft_strcmp(object->name, "cone")))
			object->t = cone(ray, (t_object*)tmp->content);
		else
			object->t = FAR;
		if (object->t < obj1->t)
			obj1 = (t_object *)tmp->content;
		tmp = tmp->next;
	}
	if (obj1->t == FAR)
		return (NULL);
	return (obj1);
}

float		shadows(t_ray *ray, t_list *objects,t_list *lights,t_object *obj)
{
	t_list			*tmp1;
	t_point 		p;
	t_ray			shadow_ray;
	t_list			*tmp2;
	t_vector			n;
	int				k;
	int 			nb_light;

	k = 0;
	nb_light = 0;
	p = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	tmp2 = lights;
	while (tmp2)
	{
		shadow_ray.dir = vec_normalize(vec_sub(((t_light *)tmp2->content)->origin, p));
		n = get_normal(obj, ray);
		shadow_ray.origin = vec_sum(p, vec_kscale(MIN_D, n));
		tmp1 = objects;
		while (tmp1)
		{
			if (!(ft_strcmp(((t_object*)tmp1->content)->name, "sphere")))
				((t_object*)tmp1->content)->tsh = sphere(&shadow_ray,(t_object*)tmp1->content);
			else if (!(ft_strcmp(((t_object*)tmp1->content)->name, "plane")))
				((t_object*)tmp1->content)->tsh = plane(&shadow_ray, (t_object*)tmp1->content);
			else if (!(ft_strcmp(((t_object*)tmp1->content)->name, "cone")))
				((t_object*)tmp1->content)->tsh = cone(&shadow_ray, (t_object*)tmp1->content);
			else if (!(ft_strcmp(((t_object*)tmp1->content)->name, "cylinder")))
				((t_object*)tmp1->content)->tsh = cylinder(&shadow_ray, (t_object*)tmp1->content);
			if (((t_object*)tmp1->content)->tsh != FAR)
			{
				k++;
				break ;
			}
			tmp1 = tmp1->next;

		}
		nb_light++;
		tmp2 = tmp2->next;
	}
	if (k == nb_light)
		return(0);
	return (1);
}

int get_percent(int color, float p)
{
	unsigned char *tab;

	tab = (unsigned char *)&color;
	tab[0] = tab[0] * p;
	tab[1] = tab[1] * p;
	tab[2] = tab[2] * p;
	return	(color);
}

void	draw(t_mlx *mlx, t_camera cam,t_list *objects, t_list *lights)
{
	int			i;
	int			j;
	t_object	*obj;
	t_ray 		ray;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			obj = ramplir(cam, objects, i, j, &ray);
			if (obj == NULL)
			{
				ft_mlx_pixel_put(mlx, i, j, 0);
				continue ;
			}
			obj->k = shadows(&ray, objects, lights, obj);
			ft_mlx_pixel_put(mlx, i, j,  phong_model(obj, &ray, lights, obj->k));
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void create_actual_objs(t_mlx *mlx, t_camera camera, t_list *lights, t_list *objects)
{
	draw(mlx, camera, objects, lights);
}
