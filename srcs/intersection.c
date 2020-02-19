/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 23:00:09 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/19 16:01:58 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		solution(float a, float b, float c, double *t)
{
	double t1;
	double t2;

	if ((b * b - 4 * a * c) < 0)
		return (FALSE);
	if ((b * b - 4 * a * c) == 0)
		return (-b / 2 * a);
	t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (t1 < t2 && t1 >= 0 && t1 < FAR)
	{
		*t = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0 && t2 < 1000000)
	{
		*t = t2;
		return (1);
	}
	return(FALSE);
}

double		sphere(t_ray *ray, t_object *obj, double *t)
{
	float a;
	float b;
	float c;

	a = vec_dot(ray->dir, ray->dir);
	b = vec_dot(vec_kscale(2, ray->dir), vec_sub(ray->origin, obj->center));
	c = vec_dot(vec_sub(ray->origin, obj->center), vec_sub(ray->origin, obj->center)) - obj->radius * obj->radius;
	return (solution(a, b, c, t));
}

double	cylinder(t_ray *ray, t_object *obj, double *t)
{
	float a;
	float b;
	float c;
	t_vec	delta_p;

	obj->center.x = 0; obj->center.y = 0; obj->center.z = 0;
	obj->vec_dir.x = 0 ; obj->vec_dir.y = 1; obj->vec_dir.z = 0;
	obj->radius = 1.5;

	delta_p = vec_sub(ray->origin, obj->center);
	a = vec_dot(vec_sub(ray->dir, vec_kscale(vec_dot(ray->dir, obj->vec_dir), obj->vec_dir)),vec_sub(ray->dir, vec_kscale(vec_dot(ray->dir, obj->vec_dir), obj->vec_dir)));
	b = 2 * vec_dot(vec_sub(ray->dir, vec_kscale(vec_dot(ray->dir, obj->vec_dir), obj->vec_dir)),(vec_sub(delta_p, vec_kscale(vec_dot(delta_p, obj->vec_dir), obj->vec_dir))));
	c = vec_dot(vec_sub(delta_p, vec_kscale(vec_dot(delta_p, obj->vec_dir), obj->vec_dir)), vec_sub(delta_p, vec_kscale(vec_dot(delta_p, obj->vec_dir), obj->vec_dir))) - (obj->radius * obj->radius);
	return (solution(a, b, c, t));
}

double	plane(t_ray *ray, t_object *obj, double *t)
{
	t_vec p0l0;
	float	t1;
	float	denom;
	
	denom = vec_dot(obj->vec_dir, ray->dir);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = vec_sub(obj->center , ray->origin);
		t1 = vec_dot(p0l0, obj->vec_dir) / denom;
		if (t1 >= 0)
		{
			*t = t1;
			return (1);
		}
	}
	return (FALSE); 
}

double 		cone(t_ray *ray, t_object *obj, double *t)
{
	float 	a;
	float 	b;
	float 	c;
	float 	v_va;
	
	t_vec delta_p = vec_sub(ray->origin, obj->center);
	v_va = vec_dot(ray->dir, obj->vec_dir);
	a = pow(cos(obj->alpha), 2) * vec_dot(vec_sub(ray->dir, vec_kscale(v_va,obj->vec_dir)), vec_sub( ray->dir, vec_kscale(v_va,obj->vec_dir))) - pow(sin(obj->alpha),2) * v_va * v_va;
	b = 2 * pow(cos(obj->alpha), 2) * vec_dot(vec_sub(ray->dir, vec_kscale(v_va,obj->vec_dir)), vec_sub(delta_p, vec_kscale(vec_dot(delta_p,obj->vec_dir),obj->vec_dir))) - 2 * pow(sin(obj->alpha),2) * v_va * vec_dot(delta_p,obj->vec_dir);
	c = pow(cos(obj->alpha), 2) * vec_dot(vec_sub(delta_p, vec_kscale(vec_dot(delta_p,obj->vec_dir),obj->vec_dir)), vec_sub(delta_p, vec_kscale(vec_dot(delta_p,obj->vec_dir),obj->vec_dir))) - pow(sin(obj->alpha),2) * pow(vec_dot(delta_p,obj->vec_dir), 2);
	return (solution(a, b, c, t));
}