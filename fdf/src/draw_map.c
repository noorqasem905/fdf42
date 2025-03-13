/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/12 18:48:22 by nqasem           ###   ########.fr       */
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

void	draw_map_utils(t_data *fdf, t_map *a)
{
	t_map	*b;
	int		tmp;
	int		x;
	float		y;
	float	z;
	int		i;
	int		j;
	int		color;
	float	pixel_x;
	float	pixel_y;
	float	start_x;
	float	start_y;
	float	end_x;
	float	end_y;
	int		flag;
	float inc_z;
	int counter;
	
	x = a->x;
	y = a->y;
	z = a->z;
	i = a->i;
	j = a->j;
	z *= 10;
	color = a->color;
	tmp = x;
	x = (tmp - y) * cos(PI / 6);
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	b = malloc(sizeof(t_map));
	// x *= 2;
	// y *= 2; 
	if (i < fdf->height && (j + 1) < fdf->width && (j) > 0)
	{
		if (fdf->map[i][j+1].z > 0 && fdf->map[i][j].z == 0)
		{
			int fd;
			color = 0x00FF00;
			inc_z = 100.0/160.0;
			fdf->flag += 1;
			fd = fdf->flag;
			counter = -1;
			while (++counter < fd)
			{
				z += inc_z;
				printf("ddd:%f\n", z);
			}
			y = (tmp + y) * sin(PI / 6) - z;

			set_pixel(fdf, (x * cos_x) + pixel_x, (y * sin_y + pixel_y), color);
			return ;
			// printf("z: %f\n", z);
			// printf("z: %f \n", z);
		}
	}
	y = (tmp + y) * sin(PI / 6) - z;

	free(b);
	set_pixel(fdf, (x * cos_x) + pixel_x, (y * sin_y + pixel_y), color);
}

void	draw_map(t_data *fdf, t_map *a)
{
	int	tmp;
	int x;
	int y;
	int z;
	int color;
	float pixel_x;
	float pixel_y;
	x = a->x;
	y = a->y;
	z = a->z;
	color = a->color;
	// z *= 15;
	color = 0xFFFF00;
	// tmp = x;
	// x = (x * tan(0.2)) + 0;
	// y *= tan(0.8); 
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	// y += 10;
	set_pixel(fdf, (x * cos_x) + pixel_x, ((y * sin_y) + pixel_y), color);
	// set_pixel(fdf, x + pixel_x , y + pixel_y, color);
}

/*

void	draw_map_utils(t_data *fdf, t_map *a)
{
	t_map	*b;
	int		tmp;
	int		x;
	int		y;
	int		z;
	int		i;
	int		j;
	int		color;
	float	pixel_x;
	float	pixel_y;
	float	start_x;
	float	start_y;
	float	end_x;
	float	end_y;
	int		flag;
	
	x = a->x;
	y = a->y;
	z = a->z;
	i = a->i;
	j = a->j;
	color = a->color;
	z *= 1;
	tmp = x;
	x = (tmp - y) * cos(PI / 6);
	y = (tmp + y) * sin(PI / 6) - z;
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	b = malloc(sizeof(t_map));
	// x *= 2;
	// y *= 2; 
	if (i < fdf->height && (j + 1) < fdf->width && (j) > 0)
	{
		if (fdf->map[i][j+1].z == 0 && fdf->map[i][j].z > 0)
		{
			// start_x = fdf->pixel_x * (j);
			// start_y = fdf->pixel_y * (i);
			// end_x = (start_x + fdf->pixel_x);
			// end_y = (start_y + fdf->pixel_y);
			fdf->flag += 1;
			if (fdf->flag == 1)
			{
				printf("(%d, %d)\n", x, y);
				printf("start x: %f, start y:%f\n", start_x, start_y);
				printf("end x: %f, end y:%f\n", end_x, end_y);
				start_x = x;
				start_y = y;
			}
			return ;
		}
	}
	if (fdf->flag && fdf->map[i][j].z == 0)
	{
		printf("in THE END(%d, %d)\n", x, y);
		b->x = start_x;
		b->y = start_y;
		// b->z =fdf->map[i][j].z;
		// slope(fdf, b, end_x, end_y);
		// printf("end y: %f, start y:%f\n", end_y, start_y);
		color = 0x00FFFF;
		slope(fdf, b, x, y);		
		fdf->flag = 0;
		return ;
	}
	free(b);
	set_pixel(fdf, (x * cos_x) + pixel_x, (y * sin_y + pixel_y), color);
}

*/