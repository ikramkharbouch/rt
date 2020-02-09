/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:49:57 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/08 23:54:18 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

int     manage_rtv1(char *filename, t_mlx *mlx)
{
    t_parser *p;

    if (!(p = get_data(filename)))
        return (0);
    if (!check(p))
        return (0);
    if (!(env_setup(mlx, p)))
        return (0);
    
    debug_obj();
    debug_light();

    return (1);
}