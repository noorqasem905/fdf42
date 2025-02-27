/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:37:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/27 22:55:35 by nqasem           ###   ########.fr       */
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
		draw_map(fdf, a->x, a->y, 0xFF0000);
		printf("(%d, %d)\n", a->x, a->y);
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
		draw_map(fdf, a->x, a->y, 0xFF0000);
		printf("(%d, %d)\n", a->x, a->y);
	}
}

int	sset_algo(t_data *fdf)
{
	int		dx;
	int		dy;
	int		i;
	t_map	*a;
	t_map	*b;

	a = malloc(sizeof(t_map));
	b = malloc(sizeof(t_map));
	a->x = 0;
	a->y = 0;
	b->x = WIDTH - 1;
	b->y = 0;
	dx = b->x - a->x;
	dy = b->y - a->y;
	i = -1;
	// 4/200 50
	// if the slope is less than 1
	// while (++i < WIDTH/fdf->width)
	// {

	// }
	
	if (ft_abs(dy) < ft_abs(dx))
		slope_less_then_one(dx, dy, a, b, fdf);
	else
		slope_greater_then_one(dx, dy, a, b, fdf);
	return (0);
	// if the slope is greater than 1
}
