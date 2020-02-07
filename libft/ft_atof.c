/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 01:48:02 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/01/20 01:48:10 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float ft_atof(char *str)
{
	float nbr;
	float r;
	int i;
	int l;
	i = 0;
	l = 1;
	nbr = (float)atoi(str);
	r = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			while (str[++i] != '\0')
			{
				r = r + (str[i] - '0') * pow(10, -l);
				l++;
			}
		}
		i++;
	}
	if (nbr < 0)
		return (nbr - r);
	return (nbr + r);
}