/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:29:55 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/24 14:29:00 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_camera fill_camera_data(t_block *block)
{
	t_block_list 	*list;
	t_camera 		camera;
	int 			key;

	list = block->list;
	init_cam(&camera);
	while (list)
	{
		key = find_camera_key(list->key);
		if (key == EYE)
			camera.eye = vec_sum(char_to_vec(list->value), (t_vector){0.1, 0.1, 0.1});
		if (key == LOOK_AT)
			camera.look_at = char_to_vec(list->value);
		if (key == FOV)
			camera.fov = ft_atof(list->value);
		list = list->next;
	}
	return (camera);
}

t_list *fill_light_data(t_block *block)
{
	t_block_list 	*list;
	t_light 		light;
	int 			key;

	list = block->list;
	init_light(&light);
	while (list)
	{
		key = find_light_key(list->key);
		if (key == ORIGIN)
			light.origin = char_to_vec(list->value);
		if (key == INTENSITY)
			light.intensity = ft_atof(list->value);
		list = list->next;
	}
	return (ft_lstnew(&light, sizeof(t_light)));
}

t_list *fill_object_data(t_block *block)
{
	t_block_list 	*list;
	t_object		obj;
	int 			key;

	list = block->list;
	init_obj(&obj);
	while (list)
	{
		key = find_object_key(list->key);
		if (key == NAME)
			obj.name = list->value;
		if (key == COLOR)
			obj.color = ft_atoi(list->value);
		if (key == CENTER)
			obj.center = char_to_vec(list->value);
		if (key == ALPHA)
			obj.alpha = DEG_TO_RAD(ft_atof(list->value));
		if (key == VEC_DIR)
			obj.vec_dir = vec_normalize(char_to_vec(list->value));
		if (key == RADIUS)
			obj.radius = ft_atof(list->value);
		if (key == LIGHT_COEFFS)
			obj.coeffs = char_to_coeffs(list->value);
		if (key == ROT)
			obj.rot = char_to_rot(list->value);
		if (key == TRANS)
			obj.trans = char_to_trans(list->value);
		list = list->next;
	}
	return (ft_lstnew(&obj, sizeof(t_object)));
}

int fill(t_parser *p, t_mlx *mlx)
{
	t_block		*block;
	t_camera	camera;
	t_list		*lights;
	t_list		*objects;
	int			key;

	objects = NULL;
	lights = NULL;
	block = p->blocks;
	while (block)
	{
		key = find_block(block);
		if (key == CAMERA)
			camera = fill_camera_data(block);
		if (key == LIGHT)
			ft_lstadd(&lights, fill_light_data(block));
		if (key == SHAPE)
			ft_lstadd(&objects, fill_object_data(block));
		block = block->next;
	}
	translate(objects);
	rotate(&objects);
	create_actual_objs(mlx, camera, lights, objects);
	return (1);
}
