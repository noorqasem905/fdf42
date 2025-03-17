/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:37:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/17 01:22:17 by nqasem           ###   ########.fr       */
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
		draw_map(fdf, a);
	}
}

void	slope_greater_then_one(int dx, int dy, t_map *a, t_data *fdf)
{
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
		}
		draw_map(fdf, a);
	}
}
