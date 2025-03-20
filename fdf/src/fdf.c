/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:44:18 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/20 16:24:01 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	t_data	fdf;

	fdf.flag = 0;
	fdf.press = 0;
	fdf.zoom = 50;
	if (argc != 2)
	{
		handle_error("Error\n");
		return (0);
	}
	if (setup_fdf(&fdf, argv[1]))
	{
		if (fdf.flag == 12)
			handle_error(ERO_MALLOC);
		return (fdf.flag);
	}
	setup_win(&fdf);
	frees(&fdf);
}
