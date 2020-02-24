/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:05:27 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/24 14:49:09 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		sphere_keys(t_block_list *sphere, int size)
{
	int		key;

	while (sphere && size)
	{
		key = find_object_key(sphere->key);
		if (size == 7 && (key != NAME))
			return (0);
		if (size == 6 && (key != CENTER))
			return (0);
		if (size == 5 && (key != RADIUS))
			return (0);
		if (size == 4 && (key != LIGHT_COEFFS))
			return (0);
		if (size == 3 && (key != COLOR))
			return (0);
		if (size == 2 && (key != ROT))
			return (0);
		if (size == 1 && (key != TRANS))
			return (0);
		size--;
		sphere = sphere->next;
	}
	return (!size);
}

int		cylinder_keys(t_block_list *cylinder, int size)
{
	int		key;

	while (cylinder && size)
	{
		key = find_object_key(cylinder->key);
		if (size == 8 && (key != NAME))
			return (0);
		if (size == 7 && (key != CENTER))
			return (0);
		if (size == 6 && (key != VEC_DIR))
			return (0);
		if (size == 5 && (key != RADIUS))
			return (0);
		if (size == 4 && (key != LIGHT_COEFFS))
			return (0);
		if (size == 3 && (key != COLOR))
			return (0);
		if (size == 2 && (key != ROT))
			return (0);
		if (size == 1 && (key != TRANS))
			return (0);
		size--;
		cylinder = cylinder->next;
	}
	return (!size);
}

int		plane_keys(t_block_list *plane, int size)
{
	int		key;

	while (plane && size)
	{
		key = find_object_key(plane->key);
		if (size == 6 && (key != NAME))
			return (0);
		if (size == 5 && (key != CENTER))
			return (0);
		if (size == 4 && (key != LIGHT_COEFFS))
			return (0);
		if (size == 3 && (key != COLOR))
			return (0);
		if (size == 2 && (key != ROT))
			return (0);
		if (size == 1 && (key != ROT))
			return (0);
		size--;
		plane = plane->next;
	}
	return (!size);
}

int		cone_keys(t_block_list *cone, int size)
{
	int		key;

	while (cone && size)
	{
		key = find_object_key(cone->key);
		if (size == 8 && (key != NAME))
			return (0);
		if (size == 7 && (key != CENTER))
			return (0);
		if (size == 6 && (key != VEC_DIR))
			return (0);
		if (size == 5 && (key != ALPHA))
			return (0);
		if (size == 4 && (key != LIGHT_COEFFS))
			return (0);
		if (size == 3 && (key != COLOR))
			return (0);
		if (size == 2 && (key != ROT))
			return (0);
		if (size == 1 && (key != TRANS))
			return (0);
		size--;
		cone = cone->next;
	}
	return (!size);
}
