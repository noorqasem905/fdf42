/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/14 04:35:51 by nqasem           ###   ########.fr       */
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
/* 

void	draw_map_utils(t_data *fdf, t_map *a)
{
	int		tmp;
	float		x;
	float	y;
	float	z;
	int		i;
	int		j;
	int		color;
	float	center_x;
	float	center_y;
	float	pixel_x;
	float	pixel_y;
	int		flag;
	float	z_next;
	float inc_z;
	int counter;
	float	test;
	
	x = a->x;
	y = a->y;
	z = a->z;
	i = a->i;
	j = a->j;
	color = a->color;
	pixel_x = fdf->pixel_x;
	pixel_y = fdf->pixel_y;
	z *= 10;
	tmp = x;
	x = (tmp - y) * cos(PI / 6);
	y = (tmp + y) * sin(PI / 6) - z;
	center_x = cos(PI / 6) * (WIDTH / 2);
	center_y = sin(PI / 6) * (HEIGHT / 2);
	if (draw_2d_line(fdf, a, x, y, z, tmp))
		return ;
	if (fdf->flag && fdf->map[i][j].z > 0)
	{
		color = 0x00FFFF;
		set_pixel(fdf, (x * cos_x) + center_x, (y * sin_y + center_y), color);	
		fdf->flag = 0;
		return ;
	}
	fdf->flag = 0;
	// if ( x > 0 && y > 0)
	// {
	// 	if (fdf->press == 0)
	// 	{
	// 		fdf->test = x;
	// 	}
	// 	else if(fdf->press == 10)
	// 	{
	// 		int j = x - fdf->test;
	// 		if (j < 0)
	// 			fdf->tr = 1;
	// 		else
	// 			fdf->tr = 0;

	// 	}
	// 	if (fdf->press == 300)
	// 		fdf->press = 0;
	// 	else
	// 		fdf->press++;
	// 	if (fdf->tr)
	// 		return ;
	// }
	// printf("(%f, %f)\n", x, y);
	set_pixel(fdf, (x * cos_x) + center_x, (y * sin_y + center_y), color);
}
 */
void	draw_map(t_data *fdf, t_map *a)
{
	float x;
	float y;
	float z;
	int color;
	float pixel_x;
	float pixel_y;

	x = a->x;
	y = a->y;
	z = a->z;
	color = a->color;
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	set_pixel(fdf, (x * cos_x) + pixel_x, ((y * sin_y) + pixel_y), color);
}
