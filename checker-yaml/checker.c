/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:09:32 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 16:11:01 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			object_exists(t_parser *p)
{
	t_block *block;
	int		name;
	int		i;

	i = 0;
	block = p->blocks;
	while (i < p->n && block)
	{
		name = find_block(block);
		if (name == SHAPE)
			return (1);
		i++;
		block = block->next;
	}
	return (0);
}

int			light_exists(t_parser *p)
{
	t_block	*block;
	int		name;
	int		i;

	i = 0;
	block = p->blocks;
	while (i < p->n && block)
	{
		name = find_block(block);
		if (i == 1 && !(name == LIGHT))
			return (0);
		if (name == LIGHT)
			return (1);
		i++;
		block = block->next;
	}
	return (0);
}

int			order_exists(t_block *block)
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
		if (!(check_shape_keys(list, block->n)))
			return (0);
	return (1);
}

int			camera_exists(t_parser *p)
{
	t_block *block;
	int		counter;
	int		name;
	int		i;

	counter = 0;
	i = 0;
	block = p->blocks;
	while (i < p->n && block)
	{
		name = find_block(block);
		if (i == 0 && !(name == CAMERA))
			return (0);
		if (name == CAMERA)
			counter++;
		i++;
		block = block->next;
	}
	if (counter == 1)
		return (1);
	return (0);
}

int			check(t_parser *p)
{
	t_block *block;
	int		i;

	if (!(check_empty_parser(p)))
		return (0);
	if (!(camera_exists(p)) || !(light_exists(p)) || !(object_exists(p)))
		return (0);
	i = 0;
	block = p->blocks;
	while (i < p->n && block)
	{
		if (!order_exists(block))
			return (0);
		i++;
		block = block->next;
	}
	return (1);
}
