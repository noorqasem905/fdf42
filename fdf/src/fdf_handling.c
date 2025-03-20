/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:46 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/20 22:13:28 by nqasem           ###   ########.fr       */
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

void	frees_split(char **root)
{
	int	i;

	i = 0;
	while (root[i])
	{
		free(root[i]);
		i++;
	}
	free(root);
}

void	handle_error(char *_error)
{
	ft_putendl_fd(_error, 2);
}

int	q_get_dimensions_handling(t_data *fdf, int *is_changed)
{
	if ((*is_changed) != (fdf)->width && (fdf)->height != 0)
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
		ft_putnbr_fd((fdf)->height, 2);
		write(2, "\nAt column: ", 13);
		ft_putnbr_fd((fdf)->width, 2);
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