/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_axes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:06:53 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 18:09:52 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec		rotate_x_axis(t_vec vec_dir, float angle)
{
	angle = DEG_TO_RAD(angle);
	vec_dir.x = vec_dir.x;
	vec_dir.y = (vec_dir.y * cos(angle)) - (vec_dir.z * sin(angle));
	vec_dir.z = (vec_dir.y * sin(angle)) + (vec_dir.z * cos(angle));
	return (vec_dir);
}

t_vec		rotate_y_axis(t_vec vec_dir, float angle)
{
	angle = DEG_TO_RAD(angle);
	vec_dir.y = vec_dir.y;
	vec_dir.z = (vec_dir.z * cos(angle)) - (vec_dir.x * sin(angle));
	vec_dir.x = (vec_dir.z * sin(angle)) + (vec_dir.x * cos(angle));
	return (vec_dir);
}

t_vec		rotate_z_axis(t_vec vec_dir, float angle)
{
	angle = DEG_TO_RAD(angle);
	vec_dir.z = vec_dir.z;
	vec_dir.x = (vec_dir.x * cos(angle)) - (vec_dir.y * sin(angle));
	vec_dir.y = (vec_dir.x * sin(angle)) + (vec_dir.y * cos(angle));
	return (vec_dir);
}
