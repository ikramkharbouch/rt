/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:54:36 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/14 19:35:30 by ikrkharb         ###   ########.fr       */
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
	return (-1);
}

int     find_block(t_block *block)
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

t_vec		char_to_vec(char *str)
{
	char	**values;
	t_vec	tmp;
	
	ft_strtrim(str);
	values 	= ft_strsplit(str, ' ');
	tmp.x 	= ft_atof(values[0]);
	tmp.y 	= ft_atof(values[1]);
	tmp.z 	= ft_atof(values[2]);
	return (tmp);
}

t_rot		char_to_rot(char *str)
{
	char 	**values;
	t_rot	rot;

	ft_strtrim(str);
	values 	= ft_strsplit(str, ' ');
	init_rot(&rot);
	rot.on 	= !ft_strcmp(values[0], "on") ? 1 : 0;
	if (rot.on)
	{
		rot.alpha_x = ft_atof(values[1]);
		rot.alpha_y = ft_atof(values[2]);
		rot.alpha_z = ft_atof(values[3]);
	}
	return (rot);
}

char		*shift_str(char *str)
{
	while (!ft_is_whitespace(*str))
		str++;
	return (str);
}

t_trans		char_to_trans(char *str)
{
	char 	**values;
	t_trans	trans;

	ft_strtrim(str);
	values = ft_strsplit(str, ' ');
	init_trans(&trans);
	trans.on = !ft_strcmp(values[0], "on") ? 1 : 0;
	if (trans.on)
		trans.vec = char_to_vec(shift_str(str));
	return (trans);
}