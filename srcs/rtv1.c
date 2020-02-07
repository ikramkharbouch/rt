/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:52:28 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/05 19:31:53 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
 
int         main(int ac, char *av[])
{
    t_env   *env;
    
    env = NULL;
    if (ac == 2)
    {
        t_mlx mlx;

        mlx_setup(&mlx);
        env = env_setup(&mlx);
        if (!get_and_fill_data(av[1], ))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        else
            set_mlx_hooks(&mlx);
        mlx_loop(mlx.mlx_ptr);
    }
    else
        write(1, "\033[0;31mEnter a valid filename\n", 30);
    return (0);
}