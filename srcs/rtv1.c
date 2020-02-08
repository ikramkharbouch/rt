/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:52:28 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/08 17:35:04 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

int         main(int ac, char *av[])
{
    if (ac == 2)
    {
        t_mlx mlx;

        mlx_setup(&mlx);
        if (!manage_rtv1(av[1], &mlx))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        mlx_hook(mlx.win_ptr, 4, 0, mouse_press, &mlx);
	    mlx_hook(mlx.win_ptr, 2, 0, key_press, &mlx);
	    mlx_hook(mlx.win_ptr, 17, 0, close_win, &mlx);
        mlx_loop((&(mlx))->mlx_ptr);
    }
    else
        write(1, "\033[0;31mEnter a valid filename\n", 30);
    return (0);
}