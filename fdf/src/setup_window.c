/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:18:26 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/17 01:12:04 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_d(int keycode, t_data *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx_init, fdf->img);
		mlx_destroy_window(fdf->mlx_init, fdf->mlx_win);
		mlx_destroy_display(fdf->mlx_init);
		free(fdf->mlx_init);
		frees(fdf);
		exit(0);
	}
	return (0);
}

int	close_by_cross(t_data *fdf)
{
	mlx_destroy_image(fdf->mlx_init, fdf->img);
	mlx_destroy_window(fdf->mlx_init, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx_init);
	free(fdf->mlx_init);
	frees(fdf);
	exit(0);
}

void	setup_win(t_data *fdf)
{
	fdf->mlx_init = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx_init, WIDTH, HEIGHT, "FDF");
	fdf->img = mlx_new_image(fdf->mlx_init, WIDTH, HEIGHT);
	if (sset_algo(fdf))
		close_d(ESC, fdf);
	mlx_put_image_to_window(fdf->mlx_init, fdf->mlx_win, fdf->img, 0, 0);
	mlx_hook(fdf->mlx_win, 17, 0, close_by_cross, fdf);
	mlx_hook(fdf->mlx_win, 2, 1L << 0, close_d, fdf);
	mlx_loop(fdf->mlx_init);
}
