/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:20:14 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/03 19:28:04 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

float vec_dot(t_vec v1, t_vec v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vec vec_sub(t_vec v1, t_vec v2)
{
    return ((t_vec){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vec vec_sum(t_vec v1, t_vec v2)
{
    return ((t_vec){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vec vec_scale(t_vec v1, t_vec v2)
{
    return ((t_vec){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

t_vec vec_kscale(float k, t_vec v2)
{
    return ((t_vec){k * v2.x, k * v2.y, k * v2.z});
}

t_vec vec_cross(t_vec v1, t_vec v2)
{
    t_vec res;

    res.x = (v1.y * v2.z) - (v1.z * v2.y);
    res.y = (v1.z * v2.x) - (v1.x * v2.z);
    res.z = (v1.x * v2.y) - (v1.y * v2.x);
    return (res);
}

t_vec vec_normalize(t_vec v)
{
    float norme;
    t_vec r;

    norme = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (norme == 0.0)
        return ((t_vec){0.0, 0.0, 0.0});
    r.x = v.x / norme;
    r.y = v.y / norme;
    r.z = v.z / norme;
    return (r);
}
