/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:01:01 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/08 23:56:09 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

void        debug_light(void)
{
    t_light    *light;
    t_list      *lights;

    light = (t_light *)malloc(sizeof(t_light));
    lights = g_env->scene->lights;
    while (lights)
    {
        light = lights->content;
        printf("\torigin : %f\t%f\t%f\n", light->origin.x, light->origin.y, light->origin.z);
        printf("\tintensity : %f\n", light->intensity);
        lights = lights->next;
    }
}

void        debug_obj(void)
{
    t_object    *object;
    t_list      *objects;

    objects = g_env->scene->objects;
    while (objects)
    {
        object = (t_object *)(objects->content);
        printf("name : %s\n", object->name);
        printf("\tcenter : %f\t%f\t%f\n", object->center.x, object->center.y, object->center.z);
        printf("\tradius : %f\n", object->radius);
        printf("\tks : %f\n", object->ks);
        printf("\tkd : %f\n", object->kd);
        printf("\tn : %f\n", object->n);
        printf("\tcolor : %d\n", object->color);
        objects = objects->next;
    }
}