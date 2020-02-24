/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:00:45 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 19:13:51 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		sphere_input(t_block_list *sphere, int size)
{
	int key;

	while (sphere && size)
	{
		key = find_object_key(sphere->key);
		if (key == NAME && !check_univalue(sphere->value))
			return (0);
		if (key == CENTER && !check_vec_input(sphere->value))
			return (0);
		if (key == RADIUS && !check_univalue(sphere->value))
			return (0);
		if (key == LIGHT_COEFFS && !check_vec_input(sphere->value))
			return (0);
		if (key == COLOR && !check_univalue(sphere->value))
			return (0);
		if (key == ROT && !check_transform_input(sphere->value))
			return (0);
		if (key == TRANS && !check_transform_input(sphere->value))
			return (0);
		size--;
		sphere = sphere->next;
	}
	return (1);
}

int		cylinder_input(t_block_list *cylinder, int size)
{
	int key;

	while (cylinder && size)
	{
		key = find_object_key(cylinder->key);
		if (key == NAME && !check_univalue(cylinder->value))
			return (0);
		if (key == CENTER && !check_vec_input(cylinder->value))
			return (0);
		if (key == VEC_DIR && !check_vec_input(cylinder->value))
			return (0);
		if (key == RADIUS && !check_univalue(cylinder->value))
			return (0);
		if (key == LIGHT_COEFFS && !check_vec_input(cylinder->value))
			return (0);
		if (key == COLOR && !check_univalue(cylinder->value))
			return (0);
		if (key == ROT && !check_transform_input(cylinder->value))
			return (0);
		if (key == TRANS && !check_transform_input(cylinder->value))
			return (0);
		size--;
		cylinder = cylinder->next;
	}
	return (1);
}

int		plane_input(t_block_list *plane, int size)
{
	int key;

	while (plane && size)
	{
		key = find_object_key(plane->key);
		if (key == NAME && !check_univalue(plane->value))
			return (0);
		if (key == CENTER && !check_vec_input(plane->value))
			return (0);
		if (key == LIGHT_COEFFS && !check_vec_input(plane->value))
			return (0);
		if (key == COLOR && !check_univalue(plane->value))
			return (0);
		if (key == ROT && !check_transform_input(plane->value))
			return (0);
		if (key == TRANS && !check_transform_input(plane->value))
			return (0);
		size--;
		plane = plane->next;
	}
	return (1);
}

int		cone_input(t_block_list *cone, int size)
{
	int key;

	while (cone && size)
	{
		key = find_object_key(cone->key);
		if (key == NAME && !check_univalue(cone->value))
			return (0);
		if (key == CENTER && !check_vec_input(cone->value))
			return (0);
		if (key == VEC_DIR && !check_vec_input(cone->value))
			return (0);
		if (key == ALPHA && !check_univalue(cone->value))
			return (0);
		if (key == LIGHT_COEFFS && !check_vec_input(cone->value))
			return (0);
		if (key == COLOR && !check_univalue(cone->value))
			return (0);
		if (key == ROT && !check_transform_input(cone->value))
			return (0);
		if (key == TRANS && !check_transform_input(cone->value))
			return (0);
		size--;
		cone = cone->next;
	}
	return (1);
}
