/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:59:11 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 22:29:57 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec sphere_normal(t_object *obj, t_ray *ray)
{
    t_vec   n;
    t_point i;
    i = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
    n = vec_normalize(vec_sub(i, obj->center));
    return (n);
}
t_vec  cone_normal(t_object *obj, t_ray *ray)
{
    t_vec   n;
    t_point q;
    float   dx;
    float   dy;
    float   dz;
    q = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
    dx = cos(obj->alpha) * cos(obj->alpha) * (1 - obj->vec_dir.x * obj->vec_dir.x) * (q.x - obj->center.x - obj->vec_dir.x * obj->vec_dir.x * (q.x - obj->center.x)) - sin(obj->alpha) * sin(obj->alpha) * obj->vec_dir.x * (q.x - obj->center.x);
    dy = cos(obj->alpha) * cos(obj->alpha) * (1 - obj->vec_dir.y * obj->vec_dir.y) * (q.y - obj->center.y - obj->vec_dir.y * obj->vec_dir.y * (q.y - obj->center.y)) - sin(obj->alpha) * sin(obj->alpha) * obj->vec_dir.y * (q.y - obj->center.y);
    dz = cos(obj->alpha) * cos(obj->alpha) * (1 - obj->vec_dir.z * obj->vec_dir.z) * (q.z - obj->center.z - obj->vec_dir.z * obj->vec_dir.z * (q.z - obj->center.z)) - sin(obj->alpha) * sin(obj->alpha) * obj->vec_dir.z * (q.z - obj->center.z);
    n.x = dx / sqrt(dx * dx + dy * dy + dz * dz);
    n.y = dy / sqrt(dx * dx + dy * dy + dz * dz);
    n.z = dz / sqrt(dx * dx + dy * dy + dz * dz);
    return (n);
}
t_vec   cylinder_normal(t_object *obj, t_ray *ray)
{
    t_vec   n;
    t_point i;
    i = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
    n = vec_normalize(vec_sub(vec_sub(i, obj->center), vec_kscale(vec_dot(obj->vec_dir, vec_sub(i, obj->center)), obj->vec_dir)));
    return (n);
}
t_vec   reflection_vector(t_vec nor, t_vec light)
{
    t_vec r;
    r = vec_normalize(vec_sub(vec_kscale(2 * vec_dot(nor,light), nor), light));
    return (r);
}
float   f_max(float a)
{
    if (a < 0.0)
        return (0.0);
    if (a > 1.0)
        return (1.0); 
    return (a);
}
float     specular(t_object *obj, t_light *light, t_ray *ray)
{
    t_vec   r;
    t_vec   l;
    t_point i;
    i = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
    l = vec_normalize(vec_sub(light->origin, i));
    if (!(ft_strcmp(obj->name, "sphere")))
        r = reflection_vector(sphere_normal(obj, ray), l);
	if (!(ft_strcmp(obj->name, "plane")))
        r = reflection_vector(obj->vec_dir, l);	
	if (!(ft_strcmp(obj->name, "cone")))
        r = reflection_vector(cone_normal(obj, ray), l);
	if (!(ft_strcmp(obj->name, "cylinder")))
        r = reflection_vector(cylinder_normal(obj, ray), l);
    return (obj->ks * pow(f_max(vec_dot(r, vec_kscale(-1, ray->dir))), obj->n));
}
float diffuse(t_object *obj, t_light *light, t_ray *ray)
{
    t_vec       normal;
    t_point     p;
    t_vec       light_dir;
    p = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir)); 
    light_dir = vec_normalize(vec_sub(light->origin, p));  
    if (!(ft_strcmp(obj->name, "sphere")))
        normal = sphere_normal(obj, ray);
	if (!(ft_strcmp(obj->name, "plane")))
		normal = obj->vec_dir;
	if (!(ft_strcmp(obj->name, "cone")))
		normal = cone_normal(obj, ray);
	if (!(ft_strcmp(obj->name, "cylinder")))
		normal = cylinder_normal(obj, ray);
    return (vec_dot(normal,light_dir));
}
int        phong_model(t_object *obj, t_ray *ray, t_list *lights)
{
    float   d;
    float   s;
    t_list  *tmp;
    d = 0;
    s = 0;
    tmp = lights;
    while (tmp != NULL)
    {
        d = d + fmax(0, fmin(diffuse(obj, (t_light *)tmp->content, ray), 1.0));
        s = s + fmax(0, fmin(specular(obj, (t_light *)tmp->content, ray), 1.0));
        tmp = tmp->next;
    }
    return(color_mix(obj->color, fmax(0, fmin(0.2 + d, 1.0)), fmax(0, fmin(s, 1.0))));
}