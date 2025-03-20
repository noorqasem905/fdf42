/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:35:57 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/20 17:02:17 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_color(char *split, t_data *fdf, int y, int x)
{
	int		i;
	char	*hexa;

	i = 0;
	while (split[i])
	{
		if (split[i] == ',')
		{
			i++;
			if (split[i] == '0' && (split[i + 1] == 'x' || split[i + 1] == 'X'))
			{
				i += 2;
				hexa = ft_strdup(&split[i]);
				fdf->map[y][x].color = hexa_to_int(hexa);
				free(hexa);
				break ;
			}
		}
		else
			fdf->map[y][x].color = 0xFFFFFF;
		i++;
	}
}

int	setup_set_map(t_data *fdf, int fd, int y)
{
	char	*line;
	char	**split;
	int		x;

	line = get_next_line(fd);
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (!split)
	{
		free(line);
		return (1);
	}
	x = -1;
	while (++x < fdf->width)
	{
		fdf->map[y][x].x = x;
		fdf->map[y][x].y = y;
		fdf->map[y][x].z = ft_atoi(split[x]);
		set_color(split[x], fdf, y, x);
	}
	frees_split(split);
	free(line);
	return (0);
}

void	set_map_utils(t_data *fdf, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**split;

	y = -1;
	while (++y < fdf->height)
	{
		fdf->map[y] = (t_map *)malloc(sizeof(t_map) * fdf->width);
		if (!fdf->map[y])
		{
			while (--y >= 0)
				free(fdf->map[y]);
			free(fdf->map);
			errno = ENOMEM;
			close(fd);
			fdf->flag = 12;
			return ;
		}
		if (setup_set_map(fdf, fd, y))
			break ;
	}
}

void	set_map(t_data *fdf, char *arg)
{
	int	x;
	int	y;
	int	fd;

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
	set_map_utils(fdf, fd);
	if (fdf->flag)
		return ;
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
	if (fdf->height == 0 || fdf->width == 0)
	{
		handle_error(ERO_MAP);
		fdf->flag = 9;
		return (fdf->flag);
	}
	if (fdf->flag)
		return (fdf->flag);
	if (!(fdf->flag))
		write(1, "Map is valid\n", 13);
	set_map(fdf, arg);
	return (fdf->flag);
}
