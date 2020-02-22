/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:19:21 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/22 01:47:54 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int array_length(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	check_vec_values(char *vec)
{
	char	**values;

    ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	return (array_length(values) == 3);
}

int len(t_block_list *list)
{
    int i;

    i = 0;
    while (ft_strncmp(list[i].key, "none", 4))
        i++;
    return (i);
}

int		check_empty_parser(t_parser	*p)
{
	t_block			*block;
	t_block_list	*list;

	block = p->blocks;
	if (!block)
		return (0);
	while (block)
	{
		if (!(block->name))
			return (0);
		list = block->list;
		if (!list)
			return(0);
		while (list)
		{
			if (!(list->key) || !(list->value))
				return (0);
			if (!ft_strcmp(list->key, "") || !ft_strcmp(list->value, ""))
				return (0);
			list = list->next;
		}
		block = block->next;
	}
	return (1);
}