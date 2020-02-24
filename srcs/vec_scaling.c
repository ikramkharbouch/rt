/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scaling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:17:49 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 20:49:46 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	vec_scale(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

t_vector	vec_kscale(float k, t_vector v2)
{
	return ((t_vector){k * v2.x, k * v2.y, k * v2.z});
}
