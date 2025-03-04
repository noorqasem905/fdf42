/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:35:30 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/04 23:17:11 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixel(t_data *fdf, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->line_length), &(fdf->endian));
	pixel += (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw_map(t_data *fdf, int x, int y, int color, int z)
{
	int tmp;
	
	// x *= fdf->zoom;
	// y *= fdf->zoom;
	z *= fdf->zoom;
	// y *= 20;
	if (z > 0)
	{
		color = 0x00FF00;
	}
	tmp = x;
	x = (tmp - y) * cos(0.4);
	// y = (tmp + y) * sin(0.8) - z;
	// printf("y: %f\n",(x + y) * sin(0.5) - z);
	if (ft_abs(y * tan(0.3) + z) > 0){
		
		printf("y: %d\n", ft_abs(y * tan(0.3) + z));
		y = ft_abs(y * tan(0.3) + z);
		// y = ft_abs((tmp + y) * sin(0.8) - z);
	}
	else
	{
		printf("y: %d\n", ft_abs(y * tan(0.3) + z)+1);
		y = (ft_abs(y * tan(0.3) + z)+1);
		// y = ft_abs((tmp + y) * sin(0.4) - z) + 1;
	}
	set_pixel(fdf, x, y, color);
}