/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:33:14 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 19:22:33 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		free_parser(t_parser **p)
{
	ft_memdel((void **)p);
}

int			fill_block_values(t_block *block, char *line, int key, int value)
{
	if (key)
	{
		lstadd_list(&block->list, new_list());
		block->list->key = pretty_name(line);
	}
	if (value)
	{
		if (block->list == NULL)
			return (0);
		block->list->value = ft_strtrim(line);
		block->n += 1;
	}
	return (1);
}

int			parse_block(t_block *block, int fd)
{
	char		*line;
	int			type;

	block->n = 0;
	block->list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		type = get_type(line);
		if (type == NEW_LINE)
		{
			ft_memdel((void **)&line);
			return (1);
		}
		else if (type == COMMENT)
		{
			ft_memdel((void **)&line);
			continue ;
		}
		else if (type == KEY)
			fill_block_values(block, line, 1, 0);
		else if (type == VALUE)
			fill_block_values(block, line, 0, 1);
		ft_memdel((void **)&line);
	}
	return (1);
}

int			fill_parser_values(t_parser *p, int fd, char *line)
{
	lstadd_block(&p->blocks, new_block(pretty_name(line)));
	if (!(parse_block(p->blocks, fd)))
		return (0);
	p->n += 1;
	return (1);
}

t_parser	*parse(char *filename)
{
	t_parser	*p;
	char		*line;
	int			fd;
	int			type;

	if (!(p = new_parser()))
		return (NULL);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		type = get_type(line);
		if (type == COMMENT)
		{
			ft_memdel((void **)&line);
			continue ;
		}
		else if (type == BLOCK)
			if (!fill_parser_values(p, fd, line))
				return (NULL);
		ft_memdel((void **)&line);
	}
	close(fd);
	reverse_parser(p);
	return (p);
}

/*
** For debugging purposes (To delete later)
*/

void		pretty_parser(t_parser *p)
{
	t_block			*block;
	t_block_list	*list;
	int				i;
	int				j;

	printf("Objects: %d\n", p->n);
	i = 0;
	block = p->blocks;
	while (i < p->n && block)
	{
		list = block->list;
		printf("Object: %s\n", block->name);
		j = 0;
		while (j < block->n && list)
		{
			printf("\tList:\n\t\tKey:\t%s\n\t\tValue:\t%s\n",
				list->key, list->value);
			j++;
			list = list->next;
		}
		block = block->next;
		i++;
	}
}
