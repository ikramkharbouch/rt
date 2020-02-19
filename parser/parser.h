/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:05:55 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 22:02:57 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

# define NEW_LINE	1
# define COMMENT	2
# define BLOCK		3
# define KEY		4
# define VALUE		5

typedef struct		s_block_list
{
	char			*key;
	char			*value;
}					t_block_list;

typedef struct		s_block
{
	int				n;
	char			*name;
	t_block_list	list[15];
}					t_block;

typedef struct		s_parser
{
	int				n;
	t_block			blocks[15];
}					t_parser;

t_parser			*parse(char *filename);
void				free_parser(t_parser **p);
void				pretty_parser(t_parser *p);

int					is_comment(char *str);
int					is_block(char *str);
int					is_list(char *str);
char				*pretty_name(char *str);
int					get_type(char *str);

#endif
