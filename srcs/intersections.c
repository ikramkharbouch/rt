/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:13:11 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/10 19:58:00 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

float       intersect_ray_sphere(t_ray *ray, t_object *object)
{
    t_equation  eq;

    eq.a = vec_dot(ray->dir, ray->dir);
    eq.b = 2 * vec_dot(ray->dir, vec_sub(ray->origin, object->center));
    eq.c =  vec_dot(vec_sub(ray->origin, object->center), 
            vec_sub(ray->origin, object->center)) - (object->radius * object->radius);
    eq.discr = ((eq.b * eq.b) - (4 * eq.a * eq.c));
    if (eq.discr < 0)
        return (FALSE);
    eq.t1 = (-eq.b + sqrtf(eq.discr)) / (2 * eq.a);
    eq.t2 = (-eq.b + sqrtf(eq.discr)) / (2 * eq.a);
    eq.min_t = eq.t1 <= eq.t2 ? eq.t1 : eq.t2;
    if (eq.min_t > 0)
        return (eq.min_t);
    return (FALSE);
}

float       intersect_ray_plane(void)
{

}

float       intersect_ray_cylinder(void)
{

}

float       intersect_ray_cone(void)
{

}