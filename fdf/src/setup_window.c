/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:18:26 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/22 17:21:17 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	update_value(t_data *fdf)
{
	fdf->control->x = 0;
	fdf->control->y = 0;
	fdf->control->z = 0;
	fdf->control->zoom = 1;
	fdf->control->graph_rm = 0;
}

int	control(int key, t_data *fdf)
{
	fdf->control->enter = 1;
	if (key == UP)
		fdf->control->y -= 50;
	else if (key == DOWN)
		fdf->control->y += 50;
	else if (key == RIGHT)
		fdf->control->x += 50;
	else if (key == LEFT)
		fdf->control->x -= 50;
	else if (key == ZOOM_IN)
		fdf->control->zoom += 0.1;
	else if (key == ZOOM_OUT)
		fdf->control->zoom -= 0.1;
	else if (key == SPACE && fdf->control->graph_rm == 0)
		fdf->control->graph_rm = 1;
	else if (key == SPACE && fdf->control->graph_rm == 1)
		fdf->control->graph_rm = 0;
	else if (key == RESET)
		update_value(fdf);
	return (0);
}

int	close_d(int keycode, t_data *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx_init, fdf->img);
		mlx_destroy_window(fdf->mlx_init, fdf->mlx_win);
		mlx_destroy_display(fdf->mlx_init);
		free(fdf->mlx_init);
		free(fdf->control);
		frees(fdf);
		exit(0);
	}
	else if (keycode == UP || keycode == DOWN || keycode == RIGHT
		|| keycode == LEFT || keycode == ZOOM_IN || keycode == ZOOM_OUT
		|| keycode == SPACE || keycode == RESET)
	{
		control(keycode, fdf);
		ft_bzero(fdf->addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
		sset_algo(fdf);
		mlx_put_image_to_window(fdf->mlx_init, fdf->mlx_win, fdf->img, 0, 0);
	}
	return (0);
}

int	close_by_cross(t_data *fdf)
{
	mlx_destroy_image(fdf->mlx_init, fdf->img);
	mlx_destroy_window(fdf->mlx_init, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx_init);
	free(fdf->mlx_init);
	free(fdf->control);
	frees(fdf);
	exit(0);
}

int	setup_win(t_data *fdf)
{
	fdf->control = malloc(sizeof(t_control));
	if (!fdf->control)
		return (12);
	update_value(fdf);
	fdf->control->enter = 0;
	fdf->mlx_init = mlx_init();
	if (!fdf->mlx_init)
		return (handle_mlx_error(fdf, 1));
	fdf->mlx_win = mlx_new_window(fdf->mlx_init, WIDTH, HEIGHT, "FDF");
	if (!fdf->mlx_win)
		return (handle_mlx_error(fdf, 2));
	fdf->img = mlx_new_image(fdf->mlx_init, WIDTH, HEIGHT);
	if (!fdf->img)
		return (handle_mlx_error(fdf, 3));
	fdf->addr = (unsigned int *)mlx_get_data_addr(fdf->img,
			&(fdf->bits_per_pixel), &(fdf->line_length), &(fdf->endian));
	if (sset_algo(fdf))
		close_d(ESC, fdf);
	mlx_put_image_to_window(fdf->mlx_init, fdf->mlx_win, fdf->img, 0, 0);
	mlx_hook(fdf->mlx_win, 17, 0, close_by_cross, fdf);
	mlx_hook(fdf->mlx_win, 2, 1L << 0, close_d, fdf);
	mlx_loop(fdf->mlx_init);
	return (0);
}
