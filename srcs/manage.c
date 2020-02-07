/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:49:57 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 18:06:57 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int     manage_rtv1(char *filename, t_env *env)
{
    t_parser *p;

    if (!(p = get_data(filename)))
        return (0);
    if (!check(p))
        return (0);
    if (!(fill_data(p, env)))
        return (0);
    return (1);
}