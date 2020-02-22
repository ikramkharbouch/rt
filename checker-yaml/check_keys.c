/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:07:50 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/22 01:14:55 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int check_cam_keys(t_block_list *cam)
{
	int		key;
	int		i;

	key = -1;
	i = 0;
	while (cam && i < 3)
	{
		key = find_camera_key(cam->key);
		if (key == EYE && i != 0)
			return (0);
		if (key == LOOK_AT && i != 1)
			return (0);
		if (key == FOV && i != 2)
			return (0);
		i++;
		cam = cam->next;
	}
	return (1);
}

int check_light_keys(t_block_list *light)
{
	int		key;
	int		i;

	key = -1;
	i = 0;
	while (light && i < 2)
	{
		key = find_light_key(light->key);
		if (key == ORIGIN && i != 0)
			return (0);
		if (key == INTENSITY && i != 1)
			return (0);
		i++;
		light = light->next;
	}
	return (1);
}

int check_sphere_keys(t_block_list *sphere)
{
	int		key;
	int		i;

	i = 0;
	while (sphere && i < 9)
	{
		key = find_object_key(sphere->key);
		if (key == NAME && i != 0)
			return (0);
		if (key == CENTER && i != 1)
			return (0);
		if (key == RADIUS && i != 2)
			return (0);
		if (key == KS && i != 3)
			return (0);
		if (key == KD && i != 4)
			return (0);
		if (key == N && i != 5)
			return (0);
		if (key == COLOR && i != 6)
			return (0);
		if (key == ROT && i != 7)
			return (0);
		if (key == TRANS && i != 8)
			return (0);
		i++;
		sphere = sphere->next;
	}
	if (i == 9)
		return (1);
	return (0);
}

int check_cylinder_keys(t_block_list *cylinder)
{
	int		key;
	int		i;

	i = 0;
	while (cylinder && i < 10)
	{
		key = find_object_key(cylinder->key);
		if (key == NAME && i != 0)
			return (0);
		if (key == CENTER && i != 1)
			return (0);
		if (key == VEC_DIR && i != 2)
			return (0);
		if (key == RADIUS && i != 3)
			return (0);
		if (key == KS && i != 4)
			return (0);
		if (key == KD && i != 5)
			return (0);
		if (key == N && i != 6)
			return (0);
		if (key == COLOR && i != 7)
			return (0);
		if (key == ROT && i != 8)
			return (0);
		if (key == TRANS && i != 9)
			return (0);
		i++;
		cylinder = cylinder->next;
	}
	if (i == 10)
		return (1);
	return (0);
}

int check_plane_keys(t_block_list *plane)
{
	int		key;
	int		i;

	i = 0;
	while (plane && i < 9)
	{
		key = find_object_key(plane->key);
		if (key == NAME && i != 0)
			return (0);
		if (key == CENTER && i != 1)
			return (0);
		if (key == RADIUS && i != 2)
			return (0);
		if (key == KS && i != 3)
			return (0);
		if (key == KD && i != 4)
			return (0);
		if (key == N && i != 5)
			return (0);
		if (key == COLOR && i != 6)
			return (0);
		if (key == ROT && i != 7)
			return (0);
		if (key == TRANS && i != 8)
			return (0);
		i++;
		plane = plane->next;
	}
	if (i == 9)
		return (1);
	return (0);
}

int check_cone_keys(t_block_list *cone)
{
	int		key;
	int		i;

	i = 0;
	while (cone && i < 10)
	{
		key = find_object_key(cone->key);
		if (key == NAME && i != 0)
			return (0);
		if (key == CENTER && i != 1)
			return (0);
		if (key == VEC_DIR && i != 2)
			return (0);
		if (key == ALPHA && i != 3)
			return (0);
		if (key == KS && i != 4)
			return (0);
		if (key == KD && i != 5)
			return (0);
		if (key == N && i != 6)
			return (0);
		if (key == COLOR && i != 7)
			return (0);
		if (key == ROT && i != 8)
			return (0);
		if (key == TRANS && i != 9)
			return (0);
		i++;
		cone = cone->next;
	}
	if (i == 10)
		return (1);
	return (0);
}

int check_shape_keys(t_block_list *list)
{
	int		object;

	object = 0;
	if (!ft_strcmp(list->key, "name"))
		object = find_object_name(list->value);
	if (object == SPHERE)
		return (check_sphere_keys(list));
	if (object == CYLINDER)
		return (check_cylinder_keys(list));
	if (object == CONE)
		return (check_cone_keys(list));
	if (object == PLANE)
		return (check_plane_keys(list));
	return (0);
}