/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:44:18 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/22 20:20:30 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	t_data	fdf;

	fdf.flag = 0;
	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	if (setup_fdf(&fdf, argv[1]))
	{
		printf("Error\n");
		return (0);
	}
	setup_win(&fdf);

	
}

// int	maink(void)
// {
// int	dx;
// int	dy;
// t_map	*a;
// t_map	*b;

// // check name of file which you want to open .fdf in the end
// // read from file get next line
// a = malloc(sizeof(t_map));
// b = malloc(sizeof(t_map));
// a->x = 5;
// a->y = 12;
// b->x = 15;
// b->y = 20;
// dx = b->x - a->x;
// dy = b->y - a->y;
// if (abs(dy) < abs(dx))//if the slope is less than 1
// 	slope_less_then_one(dx, dy, a, b);
// else //if the slope is greater than 1
// 	slope_greater_then_one(dx, dy, a, b);

// }
/*

int	main(void)
{
   void	*mlx;
   void	*mlx_win;
   t_data	img;

   mlx = mlx_init();
   mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
   img.img = mlx_new_image(mlx, 500, 500);
   img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
   my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
   mlx_loop(mlx);
}*/
