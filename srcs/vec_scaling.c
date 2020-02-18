/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scaling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:17:49 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 18:21:14 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec	vec_scale(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

t_vec	vec_kscale(float k, t_vec v2)
{
	return ((t_vec){k * v2.x, k * v2.y, k * v2.z});
}
