/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:56:40 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 19:59:43 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		find_camera_key(char *key)
{
	if (!ft_strcmp(key, "eye"))
		return (EYE);
	if (!ft_strcmp(key, "look_at"))
		return (LOOK_AT);
	if (!ft_strcmp(key, "fov"))
		return (FOV);
	if (!ft_strcmp(key, "dist"))
		return (DIST);
	return (-1);
}

int		find_light_key(char *key)
{
	if (!ft_strcmp(key, "origin"))
		return (ORIGIN);
	if (!ft_strcmp(key, "intensity"))
		return (INTENSITY);
	return (-1);
}

int		find_object_key(char *key)
{
	if (!(ft_strcmp(key, "name")))
		return (NAME);
	if (!(ft_strcmp(key, "color")))
		return (COLOR);
	if (!(ft_strcmp(key, "center")))
		return (CENTER);
	if (!(ft_strcmp(key, "radius")))
		return (RADIUS);
	if (!(ft_strcmp(key, "ks")))
		return (KS);
	if ((!ft_strcmp(key, "kd")))
		return (KD);
	if ((!ft_strcmp(key, "n")))
		return (N);
	if ((!ft_strcmp(key, "rot")))
		return (ROT);
	if ((!ft_strcmp(key, "trans")))
		return (TRANS);
	if ((!ft_strcmp(key, "alpha")))
		return (ALPHA);
	if ((!ft_strcmp(key, "vec_dir")))
		return (VEC_DIR);
	return (-1);
}

int		find_block(t_block *block)
{
	if (!strcmp(block->name, "camera"))
		return (CAMERA);
	if (!strcmp(block->name, "light"))
		return (LIGHT);
	if (!strcmp(block->name, "object"))
		return (SHAPE);
	return (-1);
}

int		find_object_name(char *name)
{
	if (!strcmp(name, "sphere"))
		return (SPHERE);
	if (!strcmp(name, "plane"))
		return (PLANE);
	if (!strcmp(name, "cylinder"))
		return (CYLINDER);
	if (!strcmp(name, "cone"))
		return (CONE);
	return (-1);
}
