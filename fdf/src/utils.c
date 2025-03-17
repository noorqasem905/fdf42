/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:05:48 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/17 16:27:18 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_name(char *arg, t_data *fdf)
{
	int	i;

	i = 0;
	if (access(arg, F_OK | R_OK) == -1)
	{
		fdf->flag = 15;
		handle_error(ERO_FILE);
		return ;
	}
	while (arg[i])
		i++;
	if (arg[i - 1] != 'f' || arg[i - 2] != 'd' || arg[i - 3] != 'f'
		|| arg[i - 4] != '.')
	{
		fdf->flag = 1;
		handle_error(ERO_NAME_FILE);
		return ;
	}
}

int	get_row_length(char *line, t_data *fdf)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && (line[i] != ' ' && line[i] != '-'
				&& line[i] != '+' && !line[i]))
		{
			fdf->flag = 4;
			return (++i);
		}
		if (line[i] != ' ' && line[i] != '-' && line[i] != '+'
			&& ft_isdigit(line[i]))
		{
			count++;
			while (line[i + 1] != ' ' && line[i + 1])
				i++;
		}
		i++;
	}
	return (count);
}

int	q_get_dimensions(t_data *fdf, char *arg)
{
	char	*line;
	int		is_changed;
	int		fd;

	is_changed = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		handle_error(ERO_OPEN_FILE);
		fdf->flag = 9;
		return (9);
	}
	line = get_next_line(fd);
	while (line)
	{
		(fdf)->width = get_row_length(line, fdf);
		if (q_get_dimensions_handling(fdf, &is_changed))
			return (fdf->flag);
		free(line);
		line = get_next_line(fd);
		(fdf)->height++;
	}
	free(line);
	close(fd);
	return (0);
}
