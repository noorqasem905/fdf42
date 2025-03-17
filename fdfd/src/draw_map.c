/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/17 03:08:55 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixel(t_data *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	pixel = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->line_length), &(fdf->endian));
	pixel += (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw_map(t_data *fdf, t_map *a)
{
	float x;
	float y;
	float z;
	int color;
	float center_x;
	float center_y;

	x = a->x;
	y = a->y;
	z = a->z;
	color = a->color;
	center_x = cos(PI / 6) * (WIDTH / 2);
	center_y = sin(PI / 6) * (HEIGHT / 2);
	set_pixel(fdf, (x * cos_x) + (center_x - fdf->pixel), ((y * sin_y) + (center_y + fdf->pixel)), color);	
}
