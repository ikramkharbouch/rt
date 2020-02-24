/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:18:05 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 16:32:38 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		array_len(char **array)
{
	int i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

int		check_vec_input(char *vec)
{
	char **values;

	ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	return (array_len(values) == 3);
}

int		check_transform_input(char *vec)
{
	char **values;

	ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	return (array_len(values) == 4);
}

int		check_univalue(char *vec)
{
	char **values;

	ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	return (array_len(values) == 1);
}
