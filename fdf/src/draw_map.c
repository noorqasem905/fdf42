/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/03 01:29:21 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixel(t_data *fdf, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->line_length), &(fdf->endian));
	pixel += (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw_map(t_data *fdf, int x, int y, int color, int z)
{
	int calc_x;
	int calc_y;

	calc_x =(WIDTH) /(fdf->pixel + 1);
	calc_y =y;
	printf("calc_x: %d\n" ,calc_x);
	printf("calc_y: %d\n", calc_y);
	x = x + -cos(0.82359877) * y;
	x = x * cos(0.323599);
	// y = y + sin(0.52359877) * x;
	y = y * sin(0.623599);
	if (z |calc_x | calc_y){}
	// color = fdf->map[calc_x][calc_y].color;
    set_pixel(fdf, 230+x, 100+y, color);
}