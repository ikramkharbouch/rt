/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:07:50 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/20 00:47:42 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int check_cam_keys(t_block_list *cam)
{
	if (!check_empty_values(cam, 3))
		return (0);
	else
	{
		if (ft_strcmp(cam[0].key, "eye") || !(check_vec_values(cam[0].value)))
			return (0);
		if (ft_strcmp(cam[1].key, "look_at") || !(check_vec_values(cam[1].value)))
			return (0);
		if (ft_strcmp(cam[2].key, "fov") || (ft_atof(cam[2].value) < 30 || ft_atof(cam[2].value) > 360))
			return (0);
	}
	return (1);
}

int check_light_keys(t_block_list *light)
{
	if (!check_empty_values(light, 2))
		return (0);
	else
	{
		if (ft_strcmp(light[0].key, "origin") || !(check_vec_values(light[0].value)))
			return (0);
		if (ft_strcmp(light[1].key, "intensity") || ((ft_atof(light[1].value) < 0 || ft_atof(light[1].value) > 1)))
			return (0);
	}
	return (1);
}

int check_sphere_keys(t_block_list *sphere)
{
	if (!check_empty_values(sphere, 9))
		return (0);
	else
	{
		if (ft_strcmp(sphere[0].key, "name"))
			return (0);
		if (ft_strcmp(sphere[1].key, "center") || !(check_vec_values(sphere[1].value)))
			return (0);
		if (ft_strcmp(sphere[2].key, "radius"))
			return (0);
		if (ft_strcmp(sphere[3].key, "ks") || ft_atof(sphere[3].value) < 0 || ft_atof(sphere[3].value) > 1)
			return (0);
		if (ft_strcmp(sphere[4].key, "kd") || ft_atof(sphere[4].value) < 0 || ft_atof(sphere[4].value) > 1)
			return (0);
		if (ft_strcmp(sphere[5].key, "n") || ft_atof(sphere[5].value) < 0)
			return (0);
		if (ft_strcmp(sphere[6].key, "color"))
			return (0);
		if (ft_strcmp(sphere[7].key, "rot"))
			return (0);
		if (ft_strcmp(sphere[8].key, "trans"))
			return (0);
	}
	return (1);
}

int check_cylinder_keys(t_block_list *cylinder)
{
	if (!check_empty_values(cylinder, 10))
		return (0);
	else
	{
		if (ft_strcmp(cylinder[0].key, "name"))
			return (0);
		if (ft_strcmp(cylinder[1].key, "center") || !(check_vec_values(cylinder[1].value)))
			return (0);
		if (ft_strcmp(cylinder[2].key, "vec_dir") || !(check_vec_values(cylinder[2].value)))
			return (0);
		if (ft_strcmp(cylinder[3].key, "radius") && ft_atof(cylinder[3].value) < 0)
			return (0);
		if (ft_strcmp(cylinder[4].key, "ks") || ft_atof(cylinder[4].value) < 0 || ft_atof(cylinder[4].value) > 1)
			return (0);
		if (ft_strcmp(cylinder[5].key, "kd") || ft_atof(cylinder[5].value) < 0 || ft_atof(cylinder[5].value) > 1)
			return (0);
		if (ft_strcmp(cylinder[6].key, "n") || ft_atof(cylinder[6].value) < 0)
			return (0);
		if (ft_strcmp(cylinder[7].key, "color"))
			return (0);
		if (ft_strcmp(cylinder[8].key, "rot"))
			return (0);
		if (ft_strcmp(cylinder[9].key, "trans"))
			return (0);
	}
	return (1);
}

int check_plane_keys(t_block_list *plane)
{
	if (!check_empty_values(plane, 9))
		return (0);
	else
	{
		if (ft_strcmp(plane[0].key, "name"))
			return (0);
		if (ft_strcmp(plane[1].key, "center") || !(check_vec_values(plane[1].value)))
			return (0);
		if (ft_strcmp(plane[2].key, "vec_dir") || !(check_vec_values(plane[2].value)))
			return (0);
		if (ft_strcmp(plane[3].key, "ks") || ft_atof(plane[3].value) < 0 || ft_atof(plane[3].value) > 1)
			return (0);
		if (ft_strcmp(plane[4].key, "kd") || ft_atof(plane[4].value) < 0 || ft_atof(plane[4].value) > 1)
			return (0);
		if (ft_strcmp(plane[5].key, "n") || ft_atof(plane[5].value) < 0)
			return (0);
		if (ft_strcmp(plane[6].key, "color"))
			return (0);
		if (ft_strcmp(plane[7].key, "rot"))
			return (0);
		if (ft_strcmp(plane[8].key, "trans"))
			return (0);
	}
	return (1);
}

int check_cone_keys(t_block_list *cone)
{
	if (!check_empty_values(cone, 10))
		return (0);
	else
	{
		if ((ft_strcmp(cone[0].key, "name")))
			return (0);
		if ((ft_strcmp(cone[1].key, "center")) || !(check_vec_values(cone[2].value)))
			return (0);
		if ((ft_strcmp(cone[2].key, "vec_dir")) || !(check_vec_values(cone[2].value)))
			return (0);
		if ((ft_strcmp(cone[3].key, "alpha")))
			return (0);
		if ((ft_strcmp(cone[4].key, "ks")) || ft_atof(cone[4].value) < 0 || ft_atof(cone[4].value) > 1)
			return (0);
		if ((ft_strcmp(cone[5].key, "kd")) || ft_atof(cone[5].value) < 0 || ft_atof(cone[5].value) > 1)
			return (0);
		if ((ft_strcmp(cone[6].key, "n")) || ft_atof(cone[6].value) < 0)
			return (0);
		if ((ft_strcmp(cone[7].key, "color")))
			return (0);
		if ((ft_strcmp(cone[8].key, "rot")))
			return (0);
		if ((ft_strcmp(cone[9].key, "trans")))
			return (0);
	}
	return (1);
}

int check_shape_keys(t_block_list *list)
{
	if (list[0].value)
	{
		if (!ft_strcmp(list[0].value, "sphere"))
			return (check_sphere_keys(list));
		if (!ft_strcmp(list[0].value, "cylinder"))
			return (check_cylinder_keys(list));
		if (!ft_strcmp(list[0].value, "plane"))
			return (check_plane_keys(list));
		if (!ft_strcmp(list[0].value, "cone"))
			return (check_cone_keys(list));
	}
	return (0);
}