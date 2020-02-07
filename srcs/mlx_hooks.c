/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:27:13 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/05 16:28:09 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

int mouse_press(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (button == 1)
		ft_mlx_pixel_put(mlx, x, y, 0xFFF2F2);
	return (0);
}

int key_press(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

int close_win(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}
