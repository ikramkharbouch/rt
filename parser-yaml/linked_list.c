/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:52:28 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/21 17:04:41 by ikrkharb         ###   ########.fr       */
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
	list->key = NULL;
	list->value = NULL;
	list->next = NULL;
	return (list);
}

void				lstadd_block(t_block **head, t_block *new)
{
	if (*head)
		new->next = *head;
	*head = new;
}

void				lstadd_list(t_block_list **head, t_block_list *new)
{
	if (*head)
		new->next = *head;
	*head = new;
}

void				reverse_list(t_block_list **head)
{
	t_block_list	*prev;
	t_block_list	*curr;
	t_block_list	*next;

	prev = NULL;
	curr = *head;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void				reverse_blocks(t_block **head)
{
	t_block	*prev;
	t_block	*curr;
	t_block	*next;

	prev = NULL;
	curr = *head;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void		reverse_parser(t_parser *p)
{
	t_block			*block;
	t_block_list	*list;

	reverse_blocks(&(p->blocks));
	block = p->blocks;
	while (block)
	{
		list = block->list;
		reverse_list(&list);
		block->list = list;
		block = block->next;
	}
}
