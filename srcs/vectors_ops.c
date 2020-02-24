/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:20:14 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 20:49:46 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

float	vec_dot(t_vector v1, t_vector v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vector	vec_sub(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vector	vec_sum(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vector	vec_cross(t_vector v1, t_vector v2)
{
	t_vector res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

t_vector	vec_normalize(t_vector v)
{
	float norme;
	t_vector r;

	norme = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	if (!norme)
		return ((t_vector){0.0, 0.0, 0.0});
	r.x = v.x / norme;
	r.y = v.y / norme;
	r.z = v.z / norme;
	return (r);
}
