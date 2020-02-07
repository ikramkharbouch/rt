/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_fill_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:35:37 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 17:46:11 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

void    fill_structs(t_parser *p, t_env *env)
{
    
}

int     get_data(char *filename, t_env *env)
{
    t_parser    *p;

    if (!(p = parse(filename)))
        return (0);
    return (p);
}
