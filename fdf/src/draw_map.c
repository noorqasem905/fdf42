/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/17 01:20:22 by nqasem           ###   ########.fr       */
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

int	draw_2d_line(t_data *fdf, t_map *a, float x, float y, float z, int tmp)
{
	float 	inc_z;
	float	z_next;
	float	center_x;
	float	center_y;
	int 	counter;

	center_x = cos(PI / 6) * (WIDTH / 2);
	center_y = sin(PI / 6) * (HEIGHT / 2);
	if (a->i+1 < fdf->height && (a->j + 1) < fdf->width && (a->j) > 0 && a->i > 0)
	{
		if (fdf->map[a->i][a->j+1].z > 0 && fdf->map[a->i][a->j].z == 0)
		{
			z_next = fdf->map[a->i][a->j+1].z;
			a->color = 0x00FF00;
			inc_z = (10 * z_next)/fdf->pixel_x;
			fdf->flag += 1;
			counter = -1;
			while (++counter <= fdf->flag)
				z += inc_z;
			y = (tmp + y) * sin(PI / 6) - z;
			set_pixel(fdf, (x * cos_x) + center_x, (y * sin_y + center_y), a->color);
			return (1);
		}
		else if (fdf->map[a->i][a->j+1].z == 0 && fdf->map[a->i][a->j].z > 0)
		{
			a->color = 0x00FF00;
			inc_z = (z)/fdf->pixel_x;
			fdf->flag += 1;
			counter = -1;
			while (++counter <= fdf->flag)
				z -= inc_z;
			y = (tmp + y) * sin(PI / 6) - z;
			set_pixel(fdf, (x * cos_x) + center_x, (y * sin_y + center_y), a->color);
			return (1);
		}
		// else if (fdf->map[a->i - 1][a->j].z > 0 && fdf->map[a->i][a->j].z == 0)
		{
			// a->color = 0x00FF00;
			// z_next = fdf->map[a->i - 1][a->j].z;
			// inc_z = (z_next * 10)/fdf->pixel_x;
			// fdf->flag += 1;
			// counter = -1;
			// while (++counter <= fdf->flag)
			// 	z += inc_z;
			// // x =x - z;
			// y = (tmp + y) * sin(PI / 6) - z;
			// set_pixel(fdf, (x * cos_x) + center_x, (y * sin_y + center_y), a->color);
			// return (1);
		}
	}
	return (0);
}

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
	// x = (tmp - y) * cos(PI / 6);
	
	center_x = cos(PI / 6) * (WIDTH / 2);
	center_y = sin(PI / 6) * (HEIGHT / 2);
	if (draw_2d_line(fdf, a, x, y, z, tmp))
		return ;
	y = (tmp + y) * sin(PI / 6) - z;
	if (fdf->flag && fdf->map[i][j].z > 0)
	{
		color = 0x00FFFF;
		set_pixel(fdf, (x * cos_x) + center_x, (y * sin_y + center_y), color);	
		fdf->flag = 0;
		return ;
	}
	fdf->flag = 0;
	if ( x > 0 && y > 0)
	{
		if (fdf->press == 0)
		{
			fdf->test = x;
		}
		else if(fdf->press == 10)
		{
			int j = x - fdf->test;
			if (j < 0)
				fdf->tr = 1;
			else
				fdf->tr = 0;
		}
		if (fdf->press == 300)
			fdf->press = 0;
		else
			fdf->press++;
		if (fdf->tr)
			return ;
	}
	// printf("(%f, %f)\n", x, y);
	set_pixel(fdf, (x * cos_x) + center_x, (y * sin_y + center_y), color);
}

void	draw_map(t_data *fdf, t_map *a)
{
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
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	set_pixel(fdf, (x * cos_x) + pixel_x, ((y * sin_y) + pixel_y), color);
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