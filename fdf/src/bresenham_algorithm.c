/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:37:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/11 14:15:26 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_abs(int __x)
{
	if (__x < 0)
		return (__x * -1);
	return (__x);
}

void	slope_less_then_one(int dx, int dy, t_map *a, t_data *fdf)
{
	int	pixel;
	int	p;
	int	i;

	i = -1;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	while (++i < ft_abs(dx))
	{
		if (dx > 0)
			a->x++;
		else
			a->x--;
		if (p < 0)
			p += 2 * ft_abs(dy);
		else
		{
			if (dy > 0)
				a->y++;
			else
				a->y--;
			p += 2 * (ft_abs(dy) - ft_abs(dx));
		}
		if (fdf->flag == 712){
			printf("(%d, %d)\n", a->x, a->y);
			// draw_map(fdf, a);
			// fdf->flag = 0;
			// sleep(10);
		}
		else 
		{
			// draw_map(fdf, a)
			/* code */
			// fdf->flag = 0;

			draw_map_utils(fdf, a);
		}
	}
}

void	slope_greater_then_one(int dx, int dy, t_map *a, t_data *fdf)
{
	int	pixel;
	int	p;
	int	i;

	i = -1;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	while (++i < ft_abs(dy))
	{
		if (dy > 0)
			a->y++;
		else
			a->y--;
		if (p < 0)
			p += 2 * ft_abs(dx);
		else
		{
			if (dx > 0)
				a->x++;
			else
				a->x--;
			p += 2 * (ft_abs(dx) - ft_abs(dy));
			a->x++;
		}
		if (fdf->flag == 712){
			printf("(%d, %d)\n", a->x, a->y);
			// draw_map(fdf, a);
			fdf->flag = 0;
			// sleep(10);
		}
		else
		{
			/* code */
			// fdf->flag = 0;
			draw_map_utils(fdf, a);
		}
	}
}

/*

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
			if (i != fdf->width)
			{
				a->z = fdf->map[j][i].z;
				if (a->z > 0)
					a->color = 0x0000FF;
			}
			a->x = pixel;
			b->x = pixel;
			a->y = fdf->pixel;
			fdf->pixel += pixel_y;
			b->y = fdf->pixel;
			dx = b->x - a->x;
			dy = b->y - a->y;
			if (ft_abs(dy) < ft_abs(dx))
				slope_less_then_one(dx, dy, a, fdf);
			else
				slope_greater_then_one(dx, dy, a, fdf);
		}
		pixel += pixel_x;
	}
}
 */
/*
void	set_row(t_data *fdf, int pixel_x, int pixel_y, t_map *a, t_map *b)
{
	int		i;
	int		j;
	int		dx;
	int		dy;
	float	pixel;

	fdf->flag = 5;
	i = -1;
	pixel = 0;
	while (++i <= fdf->height)
	{
		j = -1;
		fdf->pixel = 0;
		while (++j < fdf->width)
		{
			a->color = 0xFFFFFF;
			if (i != fdf->height)
			{
				a->z = fdf->map[i][j].z;
				if (a->z > 0)
					a->color = 0x0000FF;
			}
			a->y = pixel;
			b->y = pixel;
			a->x = fdf->pixel;
			fdf->pixel += pixel_x;
			b->x = fdf->pixel;
			dx = b->x - a->x;
			dy = b->y - a->y;
			if (ft_abs(dy) < ft_abs(dx))
				slope_less_then_one(dx, dy, a, fdf);
			else
				slope_greater_then_one(dx, dy, a, fdf);
		}
		pixel += pixel_y;
	}
}
 */
/*

int	sset_adlgo(t_data *fdf)
{
	int		i;
	int		j;
	int		dx;
	int		dy;
	float	pixel;
	float	pixel_x;
	float	pixel_y;
	t_map	*a;
	t_map	*b;

	i = -1;
	pixel_x = WIDTH/fdf->width;
	pixel_y = HEIGHT/fdf->height;
	pixel = 0;
	b = malloc(sizeof(t_map));
	a = malloc(sizeof(t_map));
	a->z = 0;
	fdf->flag = 5;
	while (++i <= fdf->height)
	{
		j = -1;
		fdf->pixel = 0;
		while (++j < fdf->width)
		{
			a->color = 0xFFFFFF;
			if (i != fdf->height)
			{
				a->z = fdf->map[i][j].z;
				if (a->z > 0)
					a->color = 0x0000FF;
			}
			fdf->point = i;
			a->y = pixel;
			b->y = pixel;
			a->x = fdf->pixel;
			fdf->pixel += pixel_x;
			b->x = fdf->pixel;
			dx = b->x - a->x;
			dy = b->y - a->y;
			if (ft_abs(dy) < ft_abs(dx))
				slope_less_then_one(dx, dy, a, fdf);
			else
				slope_greater_then_one(dx, dy, a, fdf);
		}
		pixel += pixel_y;
	}
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
			if (i != fdf->width)
			{
				a->z = fdf->map[j][i].z;
				if (a->z > 0)
					a->color = 0x0000FF;
			}
			a->x = pixel;
			b->x = pixel;
			a->y = fdf->pixel;
			fdf->pixel += pixel_y;
			b->y = fdf->pixel;
			dx = b->x - a->x;
			dy = b->y - a->y;
			if (ft_abs(dy) < ft_abs(dx))
				slope_less_then_one(dx, dy, a, fdf);
			else
				slope_greater_then_one(dx, dy, a, fdf);
		}
		pixel += pixel_x;
	}
	free(a);
	free(b);
	return (0);
}
*/