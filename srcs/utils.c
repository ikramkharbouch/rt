/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:28:05 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 19:01:07 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

int     find_camera_key(char *key)
{
	if (!strcmp(key, "eye"))
		return (EYE);
	if (!strcmp(key, "look_at"))
		return (LOOK_AT);
	if (!strcmp(key, "fov"))
		return (FOV);
	if (!strcmp(key, "dist"))
		return (DIST);
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