/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:09:32 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/14 16:37:32 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		light_exists(t_parser *p)
{
	t_block		*block;
	int				name;
	int				i;

	i = 0;
	while (i < p->n)
	{
		block = &(p->blocks[i]);
		name = find_block(block);
		if (i == 1 && !(name == LIGHT))
			return (0);
		if (name == LIGHT)
			return (1);
		i++;
	}
	return (0);
}

int		order_exists(t_block *block)
{
	t_block_list	*list;
	int				name;

	name = find_block(block);
	list = block->list;
	if (name == CAMERA)
	{
		if (!(block->n == 3))
			return (0);
		if (!(check_cam_keys(list)))
			return (0);
	}
	if (name == LIGHT)
	{
		if (!(block->n == 2))
			return (0);
		if (!(check_light_keys(list)))
			return (0);
	}
	if (name == SHAPE)
	{
		// if (!(block->n == 4))
		// 	return (0);
		if (!(check_shape_keys(list)))
			return (0);
	}
	return (1);
}

int		camera_exists(t_parser *p)
{
	t_block	*block;
	int			counter;
	int			name;
	int			i;
	
	
	counter = 0;
	i = 0;
	while (i < p->n)
	{
		block = &(p->blocks[i]);
		name = find_block(block);
		if (i == 0 && !(name == CAMERA))
			return (0);
		if (name == CAMERA)
			counter++;
		i++;
	}
	if (counter == 1)
		return (1);
	return (0);
}

int		check(t_parser *p)
{
	t_block		*block;
	int				i;

	if (!(camera_exists(p)) || !(light_exists(p)))
		return (0);
	i = 0;
	while (i < p->n)
	{
		block = &(p->blocks[i]);
		if (!order_exists(block))
			return (0);
		i++;
	}
	return (1);
}