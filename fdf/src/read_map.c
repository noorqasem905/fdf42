/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:35:57 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/05 17:12:38 by nqasem           ###   ########.fr       */
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

void	set_map(t_data *fdf, char *arg)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**split;

	y = -1;
	fdf->map = (t_map **)malloc(sizeof(t_map *) * fdf->height);
	if (!fdf->map)
	{
		handle_error(ERO_MALLOC);
		errno = ENOMEM;
		fdf->flag = 12;
		return ;
	}
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		handle_error(ERO_OPEN_FILE);
		return ;
	}
	while (++y < fdf->height)
	{
		fdf->map[y] = (t_map *)malloc(sizeof(t_map) * fdf->width);
		if (!fdf->map[y])
		{
			while (--y >= 0)
				free(fdf->map[y]);
			handle_error(ERO_MALLOC);
			errno = ENOMEM;
			close(fd);
			fdf->flag = 12;
			return ;
		}
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		if (!split)
		{
			free(line);
			break ;
		}
		x = -1;
		while (++x < fdf->width)
		{
			fdf->map[y][x].x = x;
			fdf->map[y][x].y = y;
			fdf->map[y][x].z = ft_atoi(split[x]);
			if (fdf->map[y][x].z < 0)
				fdf->map[y][x].color = 0x0000FF;
			else
				fdf->map[y][x].color = 0xFFFFFF;
		}
		frees_split(split);
		free(line);
	}
	close(fd);
}

int	setup_fdf(t_data *fdf, char *arg)
{
	fdf->height = 0;
	fdf->width = 0;
	fdf->flag = 0;
	check_name(arg, fdf);
	if (fdf->flag)
		return (fdf->flag);
	q_get_dimensions(fdf, arg);
	if (fdf->flag)
		return (fdf->flag);
	if (!(fdf->flag))
		write(1, "Map is valid\n", 13);
	set_map(fdf, arg);
	// print_map(fdf);
	return (fdf->flag);
}