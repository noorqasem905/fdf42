/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:56:05 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/15 18:11:44 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_isometric(t_data *fdf)
{
	float	x;
	float	y;
	float	z;
	int color;
	float pixel_x;
	float pixel_y;
	int		i;
	int		j;
	float	error;
	t_map	**map;
	int		tmp;

	fdf->flag = 0;
	error = 0;
	map = fdf->map;
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (j+1 > 0)
			{if (map[i][j].z > 0 && map[i][j-1].z == 0)
			{
				// error +=10;
			}
			else
				error  = 0;}
			tmp = (map[i][j].x);
			map[i][j].x = ((tmp*(fdf->pixel_x - error) - (y * (fdf->pixel_y))) * cos(PI / 6));
			map[i][j].y = ((tmp *(fdf->pixel_x)) + (y * fdf->pixel_y)) * sin(PI / 6) - (map[i][j].z);
		}
	}
}
void	set_column(t_data *fdf, t_map *a)
{
	float pixel_x;
	float pixel_y;
	t_map	**map;
	int		i;
	int		j;

	i = -1;
	fdf->flag = 0;
	map = fdf->map;
	pixel_y = 0;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j <=	fdf->width)
		{
			a->color = 0xFFFF00;
			a->y = map[i][j].y + pixel_y;
			a->x = map[i][j].x;
			if (map[i][j].z > 0)
				a->color = 0x0000FF;
			if (j+1 > 0)
			if (map[i][j+1].z > 0 && map[i][j].z == 0)
			{
				a->color = 0x00FFFF;
				// a->x -=50;
			}
			if (j + 1 < fdf->width)
				slope(fdf, a, ((map[i][j+1].x)), (map[i][j+1].y + pixel_y));
		}
		pixel_y +=fdf->pixel_y;
	}
}

void	set_row(t_data *fdf, t_map *a)
{
	float pixel_x;
	float pixel_y;
	t_map	**map;
	int		i;
	int		j;


	i = -1;
	fdf->flag = 0;
	map = fdf->map;
	pixel_x = 0;
	while (++i < fdf->width)
	{
		j = -1;
		pixel_y = 0;
		while (++j < fdf->height)
		{
			a->color = 0xFFFF00;
			a->y = map[j][i].y + pixel_y; 
			a->x = map[j][i].x;
			if (map[j][i].z > 0)
			a->color = 0x0000FF;
			// if (j-1 > 0)
			// if (map[j][i-1].z > 0)
			// {
			// 	a->color = 0x00FFFF;
			// }
			if (j + 1 < fdf->height)
			slope(fdf, a, ((map[j + 1][i].x)), (map[j + 1][i].y + (pixel_y + fdf->pixel_y)));
			pixel_y += fdf->pixel_y; 
		}
	}
}

int	slope(t_data *fdf, t_map *a, float x2, float y2)
{
	int		x1;
	int		y1;
	int		dx;
	int		dy;

	x1 = a->x;
	y1 = a->y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (ft_abs(dy) < ft_abs(dx))
		slope_less_then_one_test(dx, dy, a, fdf);
	else
		slope_greater_then_one_test(dx, dy, a, fdf);
	return 0;
}

int	sset_algo(t_data *fdf)
{
	float	pixel_x;
	float	pixel_y;
	t_map	*a;

	pixel_x = WIDTH / fdf->width;
	pixel_y = HEIGHT / fdf->height;
	a = malloc(sizeof(t_map));
	a->z = 0;
	fdf->flag = 0;
	fdf->press = 0;
	fdf->tr = 0;
	fdf->pixel_x = pixel_x;
	fdf->pixel_y = pixel_y;
	set_isometric(fdf);
	set_column(fdf, a);
	set_row(fdf, a);
	free(a);
	return (0);
}
