/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:18:26 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/22 01:30:10 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void setup_win(t_data *fdf)
{
    fdf->mlx_init = mlx_init();
    fdf->mlx_win = mlx_new_window(fdf->mlx_init, WIDTH, HEIGHT, "FDF");
    fdf->img = mlx_new_image(fdf->mlx_init, WIDTH, HEIGHT);
    fdf->addr = mlx_get_data_addr(fdf->mlx_init, &fdf->height, &fdf->width, &fdf->endian);
    mlx_loop(fdf->mlx_init);
}