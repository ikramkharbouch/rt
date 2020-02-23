/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:52:28 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 19:19:13 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			lstadd_block(t_block **head, t_block *new)
{
	if (*head)
		new->next = *head;
	*head = new;
}

void			lstadd_list(t_block_list **head, t_block_list *new)
{
	if (*head)
		new->next = *head;
	*head = new;
}

void			reverse_list(t_block_list **head)
{
	t_block_list *prev;
	t_block_list *curr;
	t_block_list *next;

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

void			reverse_blocks(t_block **head)
{
	t_block *prev;
	t_block *curr;
	t_block *next;

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

void			reverse_parser(t_parser *p)
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
