/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/05 17:32:34 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixel(t_data *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	pixel = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->line_length), &(fdf->endian));
	pixel += (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw_map(t_data *fdf, int x, int y, int color, int z)
{
	int	tmp;

	tmp = x;
	x = (tmp - y) * cos(3.14159 / 6);
	y = (tmp + y) * sin(3.14159 / 6) - z;
	set_pixel(fdf, (x * cos(0.9)) + 550, (y * sin(0.5)) + 150, color);
}
/* 

void	set_pixel(t_data *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	pixel = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->line_length), &(fdf->endian));
	pixel += (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw_map(t_data *fdf, t_map *a)
{
	int	tmp;

	tmp = a->x;
	a->x = (tmp - a->y) * cos(3.14159 / 6);
	a->y = (tmp + a->y) * sin(3.14159 / 6) - a->z;
	set_pixel(fdf, (a->x * cos(0.9)) + 550, (a->y * sin(0.5)) + 150, a->color);
} */

// // y *= fdf->zoom;
// z *= fdf->zoom;
// // y *= 20;
// 	printf("y: %d\n", ft_abs(y * tan(0.3) + z));

// tmp = x;
// x = (tmp - y) * cos(0.4);
// // y = (tmp + y) * sin(0.8) - z;
// if (ft_abs(y * tan(0.3) + z) > 0){

// 	y = ft_abs(y * tan(0.3) + z);
// 	// y = ft_abs((tmp + y) * sin(0.8) - z);
// }
// else
// {
// 	printf("y: %d\n", ft_abs(y * tan(0.3) + z)+1);
// 	y = (ft_abs(y * tan(0.3) + z)+1);
// 	// y = ft_abs((tmp + y) * sin(0.4) - z) + 1;
// }