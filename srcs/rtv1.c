/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:20:30 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/01/25 21:54:35 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		((unsigned int *)(mlx->img_data))[y * WIDTH + x] = color;
	}
}

void ft_draw(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, WIDTH, HEIGHT);
}

void ft_mlx_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "RTv1");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp), &(mlx->s_l), &(mlx->en));
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		t_mlx mlx;
		
		ft_mlx_window(&mlx);
		if (!(get_data(av[1], &mlx)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else
		{
			mlx_hook(mlx.win_ptr, 4, 0, mouse_press, &mlx);
			mlx_hook(mlx.win_ptr, 2, 0, key_press, &mlx);
			mlx_hook(mlx.win_ptr, 17, 0, close_win, &mlx);
			mlx_loop(mlx.mlx_ptr);
		}
	}
	else
		write(1, "\033[0;31mEnter a valid filename\n", 30);
	return (0);
}