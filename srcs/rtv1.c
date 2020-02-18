/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:20:30 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 18:29:59 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	main(int ac, char *av[])
{
	t_mlx mlx;

	if (ac == 2)
	{
		ft_mlx_setup(&mlx);
		g_env.mlx = mlx;
		if (!(get_data(av[1], &mlx)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else
			mlx_hook(mlx.win_ptr, 4, 0, mouse_press, &mlx);
			mlx_hook(mlx.win_ptr, 2, 0, key_press, &mlx);
			mlx_hook(mlx.win_ptr, 17, 0, close_win, &mlx);
			mlx_loop(mlx.mlx_ptr);
	}
	else
		write(1, "\033[0;31mEnter a valid filename\n", 30);
	return (0);
}
