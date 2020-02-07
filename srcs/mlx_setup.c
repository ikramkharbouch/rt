/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:54:32 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 17:31:58 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

void    mlx_setup(t_mlx *mlx)
{
	init_mlx_values(&mlx);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "RTv1");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &(mlx->bits_per_pixel), 
					&(mlx->size_line), &(mlx->endian));
    mlx_hook(mlx->win_ptr, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, &mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_win, &mlx);
}

void ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		((unsigned int *)(mlx->img_data))[y * WIDTH + x] = color;
	}
}