/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:19:21 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/20 00:26:26 by ikrkharb         ###   ########.fr       */
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

/*
** We don't need it anymore (To delete later)
*/

int check_empty_keys(t_block_list *list, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (list[i].key == NULL)
			return (0);
		i++;
	}
	return (1);
}

int check_empty_values(t_block_list *list, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("\ti == %d\nvalue == %s\n", i, list[i].value);
		if (!ft_strcmp(list[i].value, ""))
			return (0);
		i++;
	}
	return (1);
}

int len(t_block_list *list)
{
    int i;

    i = 0;
    while (ft_strncmp(list[i].key, "none", 4))
        i++;
    return (i);
}