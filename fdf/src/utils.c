/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:05:48 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/05 17:07:46 by nqasem           ###   ########.fr       */
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

void	print_map(t_data *fdf)
{
	int	y;
	int	x;

	for (y = 0; y < fdf->height; y++)
	{
		for (x = 0; x < fdf->width; x++)
		{
			printf("%d ", fdf->map[y][x].z);
			if (fdf->map[y][x].z <= 0 && fdf->map[y][x + 1].z <= 0)
				printf(" ");
			if (fdf->map[y][x].z > 0 && fdf->map[y][x + 1].z <= 0)
				printf(" ");
		}
		printf("\n");
	}
}
