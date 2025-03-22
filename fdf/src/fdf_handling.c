/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:46 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/22 17:21:06 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	frees(t_data *root)
{
	t_map	**cur2;
	int		i;

	i = -1;
	cur2 = (*root).map;
	while (++i < (*root).height && cur2[i])
		free(cur2[i]);
	if (cur2)
		free(cur2);
}

void	handle_error(char *_error)
{
	ft_putendl_fd(_error, 2);
}

int	handle_get_next_line(int fd, char *line, int flag)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (flag);
}

int	handle_mlx_error(t_data *fdf, int error)
{
	if (error == 1 && fdf->control)
		free(fdf->control);
	else if (error == 2 && fdf->mlx_init && fdf->control)
	{
		mlx_destroy_display(fdf->mlx_init);
		free(fdf->control);
		free(fdf->mlx_init);
		handle_error(ERO_MLX_WIN);
		return (error);
	}
	else if (error == 3 && fdf->mlx_init
		&& fdf->control && fdf->mlx_win)
	{
		mlx_destroy_window(fdf->mlx_init, fdf->mlx_win);
		mlx_destroy_display(fdf->mlx_init);
		free(fdf->mlx_init);
		free(fdf->control);
		handle_error(ERO_MLX_IMG);
		return (error);
	}
	handle_error(ERO_MLX);
	return (error);
}

int	q_get_dimensions_handling(t_data *fdf, int *is_changed)
{
	if ((*is_changed) != (fdf)->width && (fdf)->height != 0 && fdf->flag != 4)
	{
		fdf->flag = 1;
		handle_error(ERO_MAP);
		return (fdf->flag);
	}
	(*is_changed) = (fdf)->width;
	if (fdf->flag)
	{
		handle_error(ERO_MAP);
		write(2, "At line: ", 9);
		ft_putnbr_fd((fdf)->height++ +1, 2);
		write(2, "\nAt column: ", 13);
		ft_putnbr_fd((fdf)->width, 2);
		write(2, "\n", 1);
		fdf->flag = 9;
		return (fdf->flag);
	}
	return (0);
}

/* void	print_map(t_data *fdf)
{
	int	y;
	int	x;

	for (y = 0; y < fdf->height; y++)
	{
		for (x = 0; x < fdf->width; x++)
		{
			printf("%f ", fdf->map[y][x].z);
			if (fdf->map[y][x].z <= 0 && fdf->map[y][x + 1].z <= 0)
				printf(" ");
			if (fdf->map[y][x].z > 0 && fdf->map[y][x + 1].z <= 0)
				printf(" ");
		}
		printf("\n");
	}
} */