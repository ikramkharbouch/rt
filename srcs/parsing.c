/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:40:41 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/21 18:59:58 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		get_data(char *filename, t_mlx *mlx)
{
	t_parser	*p;
	(void)mlx;

	if (!(p = parse(filename)))
		return (0);
	if (!check(p))
		return (0);
	fill(p, mlx); // Fill in the structs
	pretty_parser(p);
	free_parser(&p);
	return (1);
}