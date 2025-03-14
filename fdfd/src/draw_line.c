/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:56:05 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/14 05:15:39 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	setup_column(t_data *fdf, int pixel_y, float *pixel, int i, int j,
		t_map *a)
{
	t_map	*b;
	int		dx;
	int		dy;

	b = malloc(sizeof(t_map));
	a->color = 0xFFFFFF;
	if (i != fdf->width)
	{
		a->z = fdf->map[j][i].z;
		if (a->z > 0)
			a->color = 0x0000FF;
	}
	a->x = *pixel;
	b->x = *pixel;
	a->y = fdf->pixel;
	fdf->pixel += pixel_y;
	b->y = fdf->pixel;
	dx = b->x - a->x;
	dy = b->y - a->y;
	write(1, "--------------> i am not here\n", 30);
	if (ft_abs(dy) < ft_abs(dx))
		slope_less_then_one(dx, dy, a, fdf);
	else
		slope_greater_then_one(dx, dy, a, fdf);
	free(b);
}

void	set_column(t_data *fdf, t_map *a)
{
	int		i;
	int		j;
	float pixel_x;
	float pixel_y;
	int l=60;
	t_map	**map;

	i = -1;
	fdf->flag = 0;
	map = fdf->map;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			a->color = 0xFFFF00;
			pixel_x = cos(PI / 6) * (WIDTH / 2);
			pixel_y = sin(PI / 6) * (HEIGHT / 2);
			set_pixel(fdf, (map[i][j].x * 70) + pixel_x, ((map[i][j].y*l) + pixel_y), a->color);
			printf("(%d, %d)\n", i, j);
		}
		l +=10;
	}
}

void	setup_row(t_data *fdf, int pixel_x, float *pixel, int i, int j,
		t_map *a)
{
	t_map	*b;
	int		dx;
	int		dy;

	b = malloc(sizeof(t_map));
	if (i != fdf->height)
	{
		a->z = fdf->map[i][j].z;
		if (a->z > 0)
			a->color = 0x0000FF;
	}
	a->y = *pixel;
	b->y = *pixel;
	a->x = fdf->pixel;
	fdf->pixel += pixel_x;
	b->x = fdf->pixel;
	dx = b->x - a->x;
	dy = b->y - a->y;
	write(1, "-------------->i am here\n", 25);
	if (ft_abs(dy) < ft_abs(dx))
		slope_less_then_one(dx, dy, a, fdf);
	else
		slope_greater_then_one(dx, dy, a, fdf);
	free(b);
}

void	set_row(t_data *fdf, t_map *a)
{
	int		i;
	int		j;
	float pixel_x;
	float pixel_y;
	t_map	**map;

	fdf->flag = 0;
	i = -1;
 	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			a->color = 0xFFFF00;
			pixel_x = cos(PI / 6) * (WIDTH / 2);
			pixel_y = sin(PI / 6) * (HEIGHT / 2);
			set_pixel(fdf, (map[i][j].x * 15) + pixel_x, ((map[i][j].y*15) + pixel_y), a->color);
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
	t_map	**map;
	int		tmp;

	fdf->flag = 0;
	map = fdf->map;
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			color = 0xFFFF00;
			tmp = map[i][j].x;
			map[i][j].x = (tmp - y) * cos(PI / 6);
			map[i][j].y = (tmp + y) * sin(PI / 6) - map[i][j].z;
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
	a = malloc(sizeof(t_map));
	a->z = 0;
	fdf->flag = 0;
	fdf->press = 0;
	fdf->tr = 0;
	fdf->pixel_x = pixel_x;
	fdf->pixel_y = pixel_y;
	set_isometric(fdf);
	set_column(fdf, a);
	// set_row(fdf, a);
	free(a);
	return (0);
}
