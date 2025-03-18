/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:18:26 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/18 22:44:37 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	update_value(t_data *fdf)
{
	fdf->control->x = 0;
	fdf->control->y = 0;
	fdf->control->zoom = 0;
	fdf->control->graph_rm = 0;
}

int	control(int key, t_data *fdf)
{
	if(key == UP)
		fdf->control->y -= 50;
	else if(key == DOWN)
		fdf->control->y += 50;
	else if(key == RIGHT)
		fdf->control->x += 50;
	else if(key == LEFT)
		fdf->control->x -= 50;
	else if(key == ZOOM_IN)
		fdf->control->zoom += 10;
	else if(key == ZOOM_OUT)
		fdf->control->zoom -= 10;
	else if(key == SPACE)
		fdf->control->graph_rm = 1;
	return (0);
}

int	close_d(int keycode, t_data *fdf)
{
	printf("Key: %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx_init, fdf->img);
		mlx_destroy_window(fdf->mlx_init, fdf->mlx_win);
		mlx_destroy_display(fdf->mlx_init);
		free(fdf->mlx_init);
		frees(fdf);
		exit(0);
	}
	else if(keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT
		|| keycode == ZOOM_IN || keycode == ZOOM_OUT || keycode == SPACE)
	{	
		control(keycode, fdf);
		sset_algo(fdf);
		// mlx_put_image_to_window(fdf->mlx_init, fdf->mlx_win, fdf->img, 0, 0);
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
	update_value(fdf);
	fdf->addr = (unsigned int *)mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->line_length), &(fdf->endian));
	if (sset_algo(fdf))
		close_d(ESC, fdf);
	mlx_put_image_to_window(fdf->mlx_init, fdf->mlx_win, fdf->img, 0, 0);
	mlx_hook(fdf->mlx_win, 17, 0, close_by_cross, fdf);
	mlx_hook(fdf->mlx_win, 2, 1L << 0, close_d, fdf);
	mlx_loop(fdf->mlx_init);
}
