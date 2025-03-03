/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:37:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/03 23:12:15 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_abs(int __x)
{
	if (__x < 0)
		return (__x * -1);
	return (__x);
}

void	slope_less_then_one(int dx, int dy, t_map *a, t_map *b, t_data *fdf)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	if (b)
	{
	}
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
		draw_map(fdf, a->x, a->y, a->color, a->z);
		printf("(%d, %d)\n", a->x, a->y);
		printf("pixel: %d\n", fdf->pixel);
	}
}

void	slope_greater_then_one(int dx, int dy, t_map *a, t_map *b, t_data *fdf)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	if (b)
	{
	}
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
		draw_map(fdf, a->x, a->y, a->color, a->z);
		printf("(%d, %d)\n", a->x, a->y);
		printf("pixel: %d\n", fdf->pixel);
	}
}

int	sset_algo(t_data *fdf)
{
	int		dx;
	int		dy;
	int		i;
	int	pixel;
	t_map	*a;
	t_map	*b;

	a = malloc(sizeof(t_map));
	b = malloc(sizeof(t_map));
	a->color = 0xFFFFFF;
	b->color = 0xFFFFFF;
	a->x = 0;
	pixel = HEIGHT / fdf->height;
	a->y = 0;
	b->x = WIDTH - 1;
	b->y = 0;
	i = -1;
	fdf->pixel = 0;
	while (++i <= fdf->height)
	{
		a->z = i;
		dx = b->x - a->x;
		dy = b->y - a->y;
		fdf->pixel += pixel;
		if (ft_abs(dy) < ft_abs(dx))
			slope_less_then_one(dx, dy, a, b, fdf);
		else
			slope_greater_then_one(dx, dy, a, b, fdf);
		a->x = 0;
		a->y += pixel;
		b->y += pixel;
		b->x = WIDTH - 1;
	}
	a->x = 0;
	a->y = 0;
	b->x = 0;
	b->y = HEIGHT - 10;
	i = -1;
	fdf->pixel = 0;
	pixel = WIDTH / fdf->width;
	while (++i <= fdf->width)
	{
		a->z = i;
		dx = b->x - a->x;
		dy = b->y - a->y;
		if (ft_abs(dy) < ft_abs(dx))
			slope_less_then_one(dx, dy, a, b, fdf);
		else
			slope_greater_then_one(dx, dy, a, b, fdf);
		a->y = 0;
		a->x += pixel;
		b->x += pixel;
		b->y = HEIGHT -10;
		fdf->pixel += pixel;
	}
	free(a);
	free(b);
	return (0);
}
