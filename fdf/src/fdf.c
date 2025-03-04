/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:44:18 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/04 23:50:12 by nqasem           ###   ########.fr       */
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
		handle_error(ERO_MALLOC);
		return (fdf.flag);
	}
	setup_win(&fdf);
	frees(&fdf);
	free(fdf.mlx_init);
}
