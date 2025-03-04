/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:37:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/04 23:41:28 by nqasem           ###   ########.fr       */
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
	if (fdf->flag == 0)
		pixel = (HEIGHT) / fdf->height;
	else
		pixel = (WIDTH) / fdf->width;
	// printf("map[%d]: %d\n",i, (i)/pixel);
	if (pixel == 0)
		pixel = 1;
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
		if (fdf->flag == 5 && i/pixel < fdf->width)
			a->z = fdf->map[fdf->point][i/pixel].z;
		else if (fdf->flag == 0 && i/pixel < fdf->height)
			a->z = fdf->map[i/pixel][fdf->point].z;
		draw_map(fdf, a->x, a->y, a->color, a->z);
	}
}

void	slope_greater_then_one(int dx, int dy, t_map *a, t_data *fdf)
{
	int	pixel;
	int	p;
	int	i;
	i = -1;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	if (fdf->flag == 0)
		pixel = (HEIGHT) / fdf->height;
	else
		pixel = (WIDTH) / fdf->width;
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
		if (fdf->flag == 5 && i/pixel < fdf->width)
			a->z = fdf->map[fdf->point][i/pixel].z;
		else if (fdf->flag == 0 && i/pixel < fdf->height)
			a->z = fdf->map[i/pixel][fdf->point].z;
		draw_map(fdf, a->x, a->y, a->color, a->z);
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

	b = malloc(sizeof(t_map));
	a = malloc(sizeof(t_map));	
	if (!a || !b)
	{
		if (a)
			free(a);
		if (b)
			free(b);
		handle_error(ERO_MALLOC);
		errno = ENOMEM;
		fdf->flag = 1;
		return (fdf->flag);
	}
	a->color = 0xFFFFFF;
	b->color = 0xFFFFFF;
	a->x = 0;
	a->y = 0;
	b->x = WIDTH;
	b->y = 0;
	i = -1;
	fdf->pixel = 0;
	pixel = (HEIGHT) / fdf->height;
	fdf->flag = 5; 
	while (++i <= fdf->height)
	{
 		dx = b->x - a->x;
		dy = b->y - a->y;
		fdf->pixel += pixel;
		if (i != fdf->height)
			fdf->point = i;
		if (ft_abs(dy) < ft_abs(dx))
			slope_less_then_one(dx, dy, a, fdf);
		else
			slope_greater_then_one(dx, dy, a, fdf);
			
		a->x = 0;
		a->y += pixel;
		b->y += pixel;
		b->x = WIDTH;
	}
	a->x = 0;
	a->y = 0;
	b->x = 0;
	b->y = HEIGHT;
	i = -1;
	fdf->pixel = 0;
	pixel = (WIDTH) / fdf->width;
	fdf->flag = 0; 
	while (++i <= fdf->width)
	{
		dx = b->x - a->x;
		dy = b->y - a->y;
		if (i != fdf->width)
			fdf->point = i;
		if (ft_abs(dy) < ft_abs(dx))
			slope_less_then_one(dx, dy, a, fdf);
		else
			slope_greater_then_one(dx, dy, a, fdf);
		a->y = 0;
		a->x += pixel;
		b->x += pixel;
		b->y = HEIGHT;
		fdf->pixel += pixel;
	}
	free(a);
	free(b);
	return (0);
}
