/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:28:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/19 15:58:32 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_object			*Find_closest(t_camera camera, t_list *objects, int i, int j, t_ray *ray)
{
	t_object		*obj;
	t_object		*r_obj;
	t_list			*tmp;
	float			t_tmp;
	
	camera = ft_create_cam(camera.eye, camera.look_at, camera.fov);
	*ray = generate_ray(&camera, i, j);
	tmp = objects;
	r_obj = NULL;
	t_tmp = 1e30;
	while (tmp)
	{
		obj = (t_object *)(tmp->content);
		obj->t = FAR;
		if (!(ft_strcmp(obj->name, "sphere")))
		{
			if ((sphere(ray, obj, &obj->t) == 1))
				r_obj = obj;
		}
		else if (!(ft_strcmp(obj->name, "plane")))
		{
			if (plane(ray, obj, &obj->t))
				r_obj = obj;
		} 
		else if (!(ft_strcmp(obj->name, "cone")))
		{
			if ((cone(ray, obj, &obj->t) == 1))
				r_obj = obj;
		}
		else if (!(ft_strcmp(obj->name, "cylinder")))
		{
			if ((cylinder(ray, obj, &obj->t) == 1))
				r_obj = obj;
		}
		else
			obj->t = FALSE;
		tmp = tmp->next;
	}
	if (obj->t == FALSE)
		return (NULL);
	return (r_obj);
}

/*t_object			*Find_closest(t_camera camera, t_list *objects, int i, int j, t_ray *ray)
{
	t_object		*obj1;
	t_list			*tmp;

	camera = ft_create_cam(camera.eye, camera.look_at, camera.fov);
	*ray = generate_ray(&camera, i, j);
	rotate(&objects);
	translate(&objects);
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
}*/

int		shadows(t_ray *ray, t_list *objects,t_list *lights,t_object *obj)
{
	t_list			*tmp;
	t_light			*light;
	t_point 		p;
	t_ray			shadow_ray;
	t_vec			n;
	
	light = (t_light *)lights->content;
	p = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	shadow_ray.dir = vec_normalize(vec_sub(light->origin, p));
	n = vec_normalize(vec_sub(obj->center,p));
	shadow_ray.origin = vec_sum(p, vec_kscale(MIN_D, shadow_ray.dir));
	tmp = objects;
	while (tmp)
	{
		if (!(ft_strcmp(((t_object*)tmp->content)->name, "sphere")))
			((t_object*)tmp->content)->tsh = sphere(&shadow_ray,(t_object*)tmp->content, &((t_object*)tmp->content)->t);
		else if (!(ft_strcmp(((t_object*)tmp->content)->name, "plane")))
			((t_object*)tmp->content)->tsh = plane(&shadow_ray, (t_object*)tmp->content, &((t_object*)tmp->content)->t);
		else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cone")))
			((t_object*)tmp->content)->tsh = cone(&shadow_ray, (t_object*)tmp->content, &((t_object*)tmp->content)->t);
		else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cylinder")))
			((t_object*)tmp->content)->tsh = cylinder(&shadow_ray, (t_object*)tmp->content,  &((t_object*)tmp->content)->t);
		if (((t_object*)tmp->content)->tsh != FALSE)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
			obj = Find_closest(cam, objects, i, j, &ray);
			if (obj == NULL)
			{	
				ft_mlx_pixel_put(mlx, i, j,0x00019);
				continue ;
			}
			obj->k = shadows(&ray, objects, lights, obj);
			ft_mlx_pixel_put(mlx, i, j, obj->k * phong_model(obj, &ray, lights));
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void create_actual_objs(t_mlx *mlx, t_camera camera, t_list *lights, t_list *objects)
{
	draw(mlx, camera, objects, lights);
}

