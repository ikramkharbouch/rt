/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:09:58 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/24 15:47:44 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_object	*rotate_axis(t_object *object)
{
	t_rot	rot;

	rot = object->rot;
	object->vec_dir = vec_normalize(rotate_z_axis(rotate_y_axis(rotate_x_axis(object->vec_dir,
	rot.alpha_x), rot.alpha_y), rot.alpha_z));
	object->center = rotate_z_axis(object->center, rot.alpha_z);
	return (object);
}

void		rotate(t_list **objects)
{
	t_list		*tmp;
	t_object	*object;

	tmp = *objects;
	while (tmp)
	{
		object = tmp->content;
		if (object->rot.on)
			object = rotate_axis(object);
		tmp->content = object;
		tmp = tmp->next;
	}
}

void		translate(t_list *objects)
{
	t_list		*tmp;
	t_object	*object;

	tmp = objects;
	while (objects)
	{
		object = objects->content;
		if (object->trans.on)
		{
			object->center.x += object->trans.vec.x;
			object->center.y += object->trans.vec.y;
			object->center.z += object->trans.vec.z;
		}
		tmp->content = object;
		objects = objects->next;
	}
	objects = tmp;
}
