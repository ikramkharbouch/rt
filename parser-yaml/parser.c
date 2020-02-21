/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:33:14 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/21 01:18:25 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	*new_parser()
{
	t_parser	*p;

	p = (t_parser *)malloc(sizeof(t_parser));
	if (!p)
		return (NULL);
	p->n = 0;
	return (p);
}

void		free_parser(t_parser **p)
{
	ft_memdel((void **)p);
}

int			parse_block(t_block *block, int fd)
{
	char	*line;
	int		type;

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
		{
			ft_lstadd(block->list, new_list());
			block->list->key = pretty_name(line);
		}
		else if (type == VALUE)
		{
			block->list->value = ft_strtrim(line);
			block->n += 1;
		}
		ft_memdel((void **)&line);
	}
	return (1);
}

t_parser 	*parse(char *filename)
{
	t_parser	*p;
	char		*line;
	int			fd;
	int			type;

	p = new_parser();
	if (!p)
		return (NULL);
	p->blocks = NULL;
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
		{
			ft_lstadd(p->blocks, new_block(pretty_name(line)));
			parse_block(&(p->blocks), fd);
			p->n += 1;
		}
		ft_memdel((void **)&line);
	}
	close(fd);
	return (p);
}

void		pretty_parser(t_parser *p)
{
	t_block			*block;
	t_block_list	*list;
	int				i;
	int				j;

	printf("Objects: %d\n", p->n);
	i = 0;
	while (i < p->n)
		{
			block = &(p->blocks[i]);
			list = block->list;
			printf("Object: %s\n", block->name);
			j = 0;
			while (j < block->n)
			{
				printf("\tList:\n\t\tKey:\t%s\n\t\tValue:\t%s\n",
					list[j].key, list[j].value);
				j++;
			}
			i++;
		}
}
