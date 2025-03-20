/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/20 22:45:30 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixel(t_data *fdf, int x, int y, int color)
{
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	fdf->addr[y * WIDTH + x] = color;
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
	if (fdf->control->graph_rm == 1 && a->z == 0)
		return ;
	set_pixel(fdf, (x * cos(COS_X) * fdf->control->zoom) + (center_x), ((y
				* sin(SIN_Y) * fdf->control->zoom) + ((center_y))), color);
}
