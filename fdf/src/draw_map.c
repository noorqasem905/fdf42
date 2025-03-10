/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/08 18:26:26 by nqasem           ###   ########.fr       */
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

void	draw_map(t_data *fdf, t_map *a)
{
	int	tmp;
	int x;
	int y;
	int z;
	int color;
	int press;
	float pixel_x1;
	float pixel_y1;
	float pixel_x;
	float pixel_y;
	int pixel;
	int counter;
	float x1;
	float y1;
	int		i;
	int		j;
	int		map_value;

	x = a->x;
	y = a->y;
	z = a->z;
	i = a->i;
	j = a->j;
	sleep(5);
	press = fdf->press;
	pixel_x1 = fdf->pixel_x;
	pixel_y1 = fdf->pixel_y;
	x1 = x;
	y1 = y;
	color = a->color;
	z *= 10;
	counter = -1;
	tmp = x;
	x = (tmp - a->y) * cos(PI / 6);
	y = (tmp + y) * sin(PI / 6) - z;
	pixel_x = cos(PI / 6) * (WIDTH / 2);
	pixel_y = sin(PI / 6) * (HEIGHT / 2);
	// x *= 5;
	// y *= 5; 
	pixel = x1/pixel_x1;
	if(pixel == x1/pixel_x1)
	{
		pixel = y1/pixel_y1;
		if(pixel == y1/pixel_y1)
		{
			while (++counter < z && z > 0)
			{
				color = 0xFBB917;
				/* 
					here i should draw the line
					the plan is to use the bresenham algorithm to draw the line
					the line should in spicific point in the draw
					so we know how to edit on y axis but we need to know how to edit on x axis and how to draw the line
					how can i draw it, we heve to detect line which will be up and take the point of x in box 
					after and the point which has to be in the top of the box

					this output work to know how to draw line in the up
				*/
				set_pixel(fdf, ((x) * cos_x) + pixel_x, ((y+counter) * sin_y + pixel_y), color);
			}	
		}
	}
	// if ()
	set_pixel(fdf, (x * cos_x) + pixel_x, (y * sin_y + pixel_y), color);
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