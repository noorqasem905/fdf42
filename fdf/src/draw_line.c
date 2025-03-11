/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:56:05 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/12 00:47:34 by nqasem           ###   ########.fr       */
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
	if (ft_abs(dy) < ft_abs(dx))
		slope_less_then_one(dx, dy, a, fdf);
	else
		slope_greater_then_one(dx, dy, a, fdf);
	free(b);
}

void	set_column(t_data *fdf, int pixel_x, int pixel_y, t_map *a)
{
	int		i;
	int		j;
	int		dx;
	int		dy;
	float	pixel;

	i = -1;
	pixel = 0;
	fdf->flag = 0;
	while (++i <= fdf->width)
	{
		j = -1;
		fdf->pixel = 0;
		while (++j < fdf->height)
		{
			a->color = 0xFFFFFF;
			setup_column(fdf, pixel_y, &pixel, i, j, a);
		}
		pixel += pixel_x;
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
	if (ft_abs(dy) < ft_abs(dx))
		slope_less_then_one(dx, dy, a, fdf);
	else
		slope_greater_then_one(dx, dy, a, fdf);
	free(b);
}

void	set_row(t_data *fdf, int pixel_x, int pixel_y, t_map *a)
{
	float	pixel;
	int		i;
	int		j;
	int		dx;
	int		dy;

	fdf->flag = 5;
	i = -1;
	pixel = 0;
	while (++i <= fdf->height)
	{
		j = -1;
		fdf->pixel = 0;
		while (++j < fdf->width)
		{
			a->i = i;
			a->j = j;
			a->color = 0xFFFFFF;
			setup_row(fdf, pixel_x, &pixel, i, j, a);
		}
		pixel += pixel_y;
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
	fdf->pixel_x = pixel_x;
	fdf->pixel_y = pixel_y;
	set_row(fdf, pixel_x, pixel_y, a);
	set_column(fdf, pixel_x, pixel_y, a);
	free(a);
	return (0);
}
