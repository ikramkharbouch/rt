/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:18:04 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 19:21:41 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser		*new_parser(void)
{
	t_parser	*p;

	p = (t_parser *)malloc(sizeof(t_parser));
	if (!p)
		return (NULL);
	p->n = 0;
	p->blocks = NULL;
	return (p);
}

t_block			*new_block(char *name)
{
	t_block *block;

	block = (t_block *)malloc(sizeof(t_block));
	if (!block)
		return (NULL);
	block->n = 0;
	block->name = name;
	block->list = NULL;
	block->next = NULL;
	return (block);
}

t_block_list	*new_list(void)
{
	t_block_list *list;

	list = (t_block_list *)malloc(sizeof(t_block_list));
	if (!list)
		return (NULL);
	list->key = NULL;
	list->value = NULL;
	list->next = NULL;
	return (list);
}
