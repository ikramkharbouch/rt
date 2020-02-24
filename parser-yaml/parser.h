/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:05:55 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 20:45:30 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define NEW_LINE	1
# define COMMENT	2
# define BLOCK		3
# define KEY		4
# define VALUE		5

typedef struct		s_block_list
{
	char				*key;
	char				*value;
	struct s_block_list	*next;
}					t_block_list;

typedef struct		s_block
{
	int				n;
	char			*name;
	t_block_list	*list;
	struct s_block	*next;
}					t_block;

typedef struct		s_parser
{
	int				n;
	t_block			*blocks;
}					t_parser;

t_parser			*parse(char *filename);
void				free_parser(t_parser **p);
void				pretty_parser(t_parser *p);
t_parser			*new_parser(void);

int					is_comment(char *str);
int					is_block(char *str);
int					is_list(char *str);
char				*pretty_name(char *str);
int					get_type(char *str);
void				init_values(t_block_list *list);

void				init_keys(t_block_list *list);

t_block				*new_block(char *name);
t_block_list		*new_list(void);
void				lstadd_block(t_block **head, t_block *new);
void				lstadd_list(t_block_list **head, t_block_list *new);
void				reverse_list(t_block_list **head);
void				reverse_blocks(t_block **head);
void				reverse_parser(t_parser *p);

#endif
