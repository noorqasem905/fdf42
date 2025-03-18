/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/18 22:45:19 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixel(t_data *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	// fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
	// 		&(fdf->line_length), &(fdf->endian));
	fdf->addr += (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
// fdf->addr += (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));

	*(unsigned int *)pixel = color;
}

void	draw_map(t_data *fdf, t_map *a)
{
	int		color;
	float	x;
	float	y;
	float	center_x;
	float	center_y;

	x = a->x;
	y = a->y;
	color = a->color;
	center_x = (cos(PI / 6) * (WIDTH / 2)) + (fdf->control->x);
	center_y = (sin(PI / 6) * (HEIGHT / 2)) + (fdf->control->y);
	set_pixel(fdf, (x * cos(COS_X)) + (center_x), ((y * sin(SIN_Y))
			+ ((center_y*2))), color);
}
