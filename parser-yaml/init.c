/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:36:58 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/20 00:24:59 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    init_keys(t_block_list *list)
{
    int i;

    i = 0;
    while (i < 15)
    {
        list[i].key = "none";
        i++;
    }
}

void    init_values(t_block_list *list)
{
    int i;

    i = 0;
    while (i < 15)
    {
        list[i].value = "";
        i++;
    }
}