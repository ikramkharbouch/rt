/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:02:02 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 19:35:13 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	color_mix(int color, float d, float s)
{
	unsigned char	*tab;

	tab = (unsigned char *)&color;
	tab[0] = (tab[0] + (255 - tab[0]) * s) * d;
	tab[1] = (tab[1] + (255 - tab[1]) * s) * d;
	tab[2] = (tab[2] + (255 - tab[2]) * s) * d;
	return (color);
}
