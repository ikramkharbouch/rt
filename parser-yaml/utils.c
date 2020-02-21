/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:53:57 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 18:46:15 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			is_comment(char *str)
{
	while (ft_is_whitespace(*str))
		str++;
	return (*str == '#');
}

int			is_block(char *str)
{
	return (strchr(str, ':') && !strchr(str, '-'));
}

int			is_list(char *str)
{
	return (strchr(str, ':') && strchr(str, '-'));
}

char		*pretty_name(char *str)
{
	int	i;

	i = 0;
	while (!ft_isalnum(str[i]))
	{
		str[i] = ' ';
		i++;
	}
	i = ft_strlen(str) - 1;
	while (!ft_isalnum(str[i]))
	{
		str[i] = ' ';
		i--;
	}
	return (ft_strtrim(str));
}

int			get_type(char *str)
{
	if (!*str)
		return (NEW_LINE);
	else if (is_comment(str))
		return (COMMENT);
	else if (is_block(str))
		return (BLOCK);
	else if (is_list(str))
		return (KEY);
	return (VALUE);
}