/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:44:18 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/17 23:12:35 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>

// #define HEIGHT 500
// #define WIDTH 800
 #include <stdio.h>

int WIDTH = 1920;
int HEIGHT = 1080;

int main()
{
    void *mlx;
    void *win;
    void *img;

    // Initialize MiniLibX
    mlx = mlx_init();
    if (mlx == NULL) {
        printf("MLX initialization failed.\n");
        return 1;
    }

    // Create a new window
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "AI Generated Image");

    // Load the AI-generated image (make sure the image is in the correct path)
    img = mlx_xpm_file_to_image(mlx, "/home/nqasem/Desktop/file core/fdf42/image01.xpm", &WIDTH, &HEIGHT);

    if (img == NULL) {
        printf("Failed to load image. Please check the path and file format.\n");
        return 1;
    }

    // Display the image in the window
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Enter the MiniLibX event loop
    mlx_loop(mlx);

    return 0;
}
