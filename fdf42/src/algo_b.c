/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:37:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/20 21:38:07 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	slope_less_then_one(int	dx,int dy, t_map *a, t_map *b)
{
	int p;
	int i;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	if(b){}
	while (++i < abs(dx))
	{
		if (dx > 0)
			a->x++;
		else
			a->x--;
		if (p < 0)
			p += 2 * abs(dy);
		else
		{
			if (dy > 0)
				a->y++;
			else
				a->y--;
			p += 2 * (abs(dy) - abs(dx));
		}
		printf("(%d, %d)\n", a->x, a->y);
	}
 }

void	slope_greater_then_one(int	dx,int dy, t_map *a, t_map *b)
{
	int p;
	int i;

	i = -1;
	p = 2 * abs(dx) - abs(dy);
	if(b){}
	while (++i < abs(dy))
	{
		if (dy > 0)
			a->y++;
		else
			a->y--;
		if (p < 0)
			p += 2 * abs(dx);
		else
		{
			if (dx > 0)
				a->x++;
			else
				a->x--;
			p += 2 * (abs(dx) - abs(dy));
			a->x++;
		}
		printf("(%d, %d)\n", a->x, a->y);
	}
}

int	hello_world()
{
	int	dx;
	int	dy;
	t_map	*a;
	t_map	*b;

	// check name of file which you want to open .fdf in the end
	// read from file get next line
	a = malloc(sizeof(t_map));
	b = malloc(sizeof(t_map));
	a->x = 5;
	a->y = 12;
	b->x = 15;
	b->y = 20;
	dx = b->x - a->x;
	dy = b->y - a->y;
    //if the slope is less than 1
	if (abs(dy) < abs(dx))
		slope_less_then_one(dx, dy, a, b);
	else
		slope_greater_then_one(dx, dy, a, b);
    return (0);
//if the slope is greater than 1
}