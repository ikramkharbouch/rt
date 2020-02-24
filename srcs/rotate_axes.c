/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_axes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:06:53 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/24 15:42:42 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		rotate_x_axis(t_vector vec_dir, float angle)
{
	float	y;

	y = vec_dir.y;
	angle = DEG_TO_RAD(angle);
	vec_dir.x = vec_dir.x;
	vec_dir.y = (vec_dir.y * cos(angle)) - (vec_dir.z * sin(angle));
	vec_dir.z = (y * sin(angle)) + (vec_dir.z * cos(angle));
	return (vec_dir);
}

t_vector		rotate_y_axis(t_vector vec_dir, float angle)
{
	float	z;

	z = vec_dir.z;
	angle = DEG_TO_RAD(angle);
	vec_dir.y = vec_dir.y;
	vec_dir.z = (vec_dir.z * cos(angle)) - (vec_dir.x * sin(angle));
	vec_dir.x = (z * sin(angle)) + (vec_dir.x * cos(angle));
	return (vec_dir);
}

t_vector		rotate_z_axis(t_vector vec_dir, float angle)
{
	float	x;

	x = vec_dir.x;
	angle = DEG_TO_RAD(angle);
	vec_dir.z = vec_dir.z;
	vec_dir.x = (vec_dir.x * cos(angle)) - (vec_dir.y * sin(angle));
	vec_dir.y = (x * sin(angle)) + (vec_dir.y * cos(angle));
	return (vec_dir);
}
