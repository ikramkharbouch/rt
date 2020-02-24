/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 23:00:09 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/23 20:52:23 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	solution(float a, float b, float c)
{
	double	t1;
	double	t2;

	if (((b * b) - (4 * a * c)) < 0)
		return (FAR);
	if ((b * b - 4 * a * c) == 0)
		return (-b / 2 * a);
	t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (t1 < t2 && t1 >= 0 && t1 < 100000)
		return (t1);
	if (t2 < t1 && t2 >= 0 && t2 < 100000)
		return (t2);
	return (FAR);
}

double	sphere(t_ray *ray, t_object *obj)
{
	float a;
	float b;
	float c;

	a = vec_dot(ray->dir, ray->dir);
	b = vec_dot(vec_kscale(2, ray->dir), vec_sub(ray->origin, obj->center));
	c = vec_dot(vec_sub(ray->origin, obj->center)
	, vec_sub(ray->origin, obj->center)) - obj->radius * obj->radius;
	return (solution(a, b, c));
}

double	cylinder(t_ray *ray, t_object *obj)
{
	float	a;
	float	b;
	float	c;
	t_vector	delta_p;

	delta_p = vec_sub(ray->origin, obj->center);
	a = vec_dot(vec_sub(ray->dir, vec_kscale(vec_dot(ray->dir, obj->vec_dir)
	, obj->vec_dir)), vec_sub(ray->dir,
	vec_kscale(vec_dot(ray->dir, obj->vec_dir), obj->vec_dir)));
	b = 2 * vec_dot(vec_sub(ray->dir, vec_kscale(vec_dot(ray->dir, obj->vec_dir)
	, obj->vec_dir)), vec_sub(delta_p, vec_kscale(vec_dot(delta_p, obj->vec_dir), obj->vec_dir)));
	c = vec_dot(vec_sub(delta_p, vec_kscale(vec_dot(delta_p, obj->vec_dir), obj->vec_dir))
		, vec_sub(delta_p, vec_kscale(vec_dot(delta_p, obj->vec_dir), obj->vec_dir)))
		- (obj->radius * obj->radius);
	return (solution(a, b, c));
}

double	plane(t_ray *ray, t_object *obj)
{
	double t;

	if (vec_dot(obj->vec_dir, ray->dir) == 0)
		return (FAR);
	t = vec_dot(vec_sub(obj->center, ray->origin), obj->vec_dir) / vec_dot(obj->vec_dir, ray->dir);
	if (t > 0 && t < 100000)
		return (t);
	return (FAR);
}

double	cone(t_ray *ray, t_object *obj)
{
	float a;
	float b;
	float c;
	float v_va;

	t_vector delta_p = vec_sub(ray->origin, obj->center);
	v_va = vec_dot(ray->dir, obj->vec_dir);
	a = pow(cos(obj->alpha), 2) * vec_dot(vec_sub(ray->dir, vec_kscale(v_va,obj->vec_dir))
	, vec_sub( ray->dir, vec_kscale(v_va,obj->vec_dir))) - pow(sin(obj->alpha),2) * v_va * v_va;
	b = 2 * pow(cos(obj->alpha), 2) * vec_dot(vec_sub(ray->dir, vec_kscale(v_va,obj->vec_dir))
	, vec_sub(delta_p, vec_kscale(vec_dot(delta_p,obj->vec_dir),obj->vec_dir)))
	- 2 * pow(sin(obj->alpha),2) * v_va * vec_dot(delta_p,obj->vec_dir);
	c = pow(cos(obj->alpha), 2) * vec_dot(vec_sub(delta_p, vec_kscale(vec_dot(delta_p,obj->vec_dir),obj->vec_dir))
	, vec_sub(delta_p, vec_kscale(vec_dot(delta_p,obj->vec_dir),obj->vec_dir)))
	- pow(sin(obj->alpha),2) * pow(vec_dot(delta_p,obj->vec_dir), 2);
	return (solution(a, b, c));
}