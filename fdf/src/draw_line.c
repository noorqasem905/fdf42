/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:56:05 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/17 18:11:45 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
		slope_less_then_one(dx, dy, a, fdf);
	else
		slope_greater_then_one(dx, dy, a, fdf);
	return (0);
}

void	set_isometric(t_data *fdf)
{
	int		i;
	int		j;
	t_map	**map;
	int		tmp;

	fdf->flag = 0;
	map = fdf->map;
	if (fdf->pixel_x > fdf->pixel_y)
		fdf->pixel = fdf->pixel_y;
	else
		fdf->pixel = fdf->pixel_x;
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			tmp = (map[i][j].x);
			map[i][j].x = (tmp - map[i][j].y) * cos(PI / 6);
			map[i][j].y = ((tmp + map[i][j].y) * sin(PI / 6)) - (map[i][j].z);
			map[i][j].x *= fdf->pixel;
			map[i][j].y *= fdf->pixel;
		}
	}
}

void	set_column(t_data *fdf, t_map *a)
{
	t_map		**map;
	int			i;
	int			j;
	int			k;

	i = -1;
	fdf->flag = 0;
	map = fdf->map;
	a->i = 0;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			a->color = map[i][j].color;
			a->y = map[i][j].y;
			a->x = map[i][j].x;
			if (j + 1 < fdf->width)
			{
				// k = fdf->pixel_x/ft_abs(map[i][j].color - map[i][j + 1].color)/fdf->pixel_x;
				// a->i = k;
				slope(fdf, a, ((map[i][j + 1].x)), (map[i][j + 1].y));
			}
		}
	}
}

void	set_row(t_data *fdf, t_map *a)
{
	t_map	**map;
	int		i;
	int		j;
	int			k;

	i = -1;
	fdf->flag = 0;
	a->i = 0;
	map = fdf->map;
	while (++i < fdf->width)
	{
		j = -1;
		while (++j < fdf->height)
		{
			a->color = map[j][i].color;
			if (j + 1 < fdf->height)
			{
				a->y = map[j + 1][i].y;
				a->x = map[j + 1][i].x;
				// k = ft_abs(map[j][i].color - map[j + 1][i].color)/fdf->pixel_x;
				// a->i = k;
				// printf("k = %d\n", k);
			}
			slope(fdf, a, ((map[j][i].x)), (map[j][i].y));
		}
	}
}

int	sset_algo(t_data *fdf)
{
	float	pixel_x;
	float	pixel_y;
	t_map	*a;

	pixel_x = WIDTH / fdf->width;
	pixel_y = HEIGHT / fdf->height;
	printf("pixel_x = %f\n", pixel_x);
	printf("pixel_y = %f\n", pixel_y);
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
