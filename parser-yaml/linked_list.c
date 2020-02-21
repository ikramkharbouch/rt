/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:52:28 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/21 01:22:13 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_block       		*new_block(char *name)
{
	t_block		*block;

	block = (t_block *)malloc(sizeof(t_block));
	if (!block)
		return (NULL);
	block->n = 0;
	block->name = name;
	block->list = NULL;
	block->next = NULL;

	return (block);
}

t_block_list		*new_list()
{
	t_block_list	*list;

	list = (t_block_list *)malloc(sizeof(t_block_list));
	if (!list)
		return (NULL);
	list->key = '\0';
	list->value = '\0';
	list->next = NULL;
	return (list);
}
