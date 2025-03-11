/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/11 17:47:17 by nqasem           ###   ########.fr       */
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
	z *= 10;
	tmp = x;
	x = (tmp - y) * cos(PI / 6);
	y = (tmp + y) * sin(PI / 6) - z;
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	if (i < fdf->height && (j + 1) < fdf->width && (j) > 0)
	{
		if (fdf->map[i][j+1].z > 0 && fdf->map[i][j].z == 0)
		{
			start_x = fdf->pixel_x * (j + 1);
			start_y = fdf->pixel_y * (i + 1);
			end_x = start_x + fdf->pixel_x;
			end_y = start_y + fdf->pixel_y;
			fdf->flag = 1;
			return ;
		}
	}
	if (fdf->flag && fdf->map[i][j].z > 0)
	{
		printf("end x: %f, start x:%f\n", end_x, start_x);
		printf("end y: %f, start y:%f\n", end_y, start_y);
		fdf->flag = 0;
	}
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
	z *= 10;

	tmp = x;
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	x = (tmp - y) * cos(PI / 6);
	y = (tmp + y) * sin(PI / 6) - z;
	set_pixel(fdf, (x * cos_x) + pixel_x, (y * sin_y + pixel_y), color);
}
// 	// y = ft_abs((tmp + y) * sin(0.8) - z);
// }
// else
// {
// 	printf("y: %d\n", ft_abs(y * tan(0.3) + z)+1);
// 	y = (ft_abs(y * tan(0.3) + z)+1);
// 	// y = ft_abs((tmp + y) * sin(0.4) - z) + 1;
// }