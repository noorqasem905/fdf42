/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:44:18 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/22 17:18:43 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	t_data	fdf;

	fdf.flag = 0;
	if (argc != 2)
	{
		handle_error("Error");
		return (0);
	}
	if (setup_fdf(&fdf, argv[1]))
	{
		if (fdf.flag == 12)
			handle_error(ERO_MALLOC);
		return (fdf.flag);
	}
	if (setup_win(&fdf) == 12)
		handle_error(ERO_MALLOC);
	frees(&fdf);
}
