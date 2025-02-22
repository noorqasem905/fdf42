/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:35:57 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/22 01:13:06 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	frees(t_data *root)
{
    t_map	**cur2;
    int i;

    i = -1;
    cur2 = (*root).map;
    while (++i < (*root).height)
        free(cur2[i]);

    free(cur2);
}
void	frees_spli5t(char **root)
{
    int i;

    i = 0;
    while (root[i])
    {
        free(root[i]);
        i++;
    }
    free(root);
}
void	frees_split(char **root)
{
    int i;

    i = 0;
    while (root[i])
    {
        free(root[i]);
        i++;
    }
    free(root);
}

void    handle_error(char *_error)
{
        ft_putendl_fd(_error, 2);
}

void    get_line(t_data *fdf, char *arg)
{
    char *line;
    int fd;
    // int ret;

    fd = open(arg, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        return ;
    }
    line = get_next_line(fd);
    fdf->height++;// you have to set default value to 0 in other place
    while (line)
    {
        line = get_next_line(fd);
        fdf->height++;
    }
    printf("%s\n", line);
    free(line);
    close(fd);
}

void   check_name(char *arg, t_data *fdf)
{
    int i;

    i = 0;
    if (access(arg, F_OK | R_OK) == -1)
    {
        fdf->flag = 15;
        handle_error(ERO_FILE);
        return ;
    }
    while (arg[i])
        i++;
    if (arg[i - 1] != 'f' || arg[i - 2] != 'd' || arg[i - 3] != 'f' || arg[i - 4] != '.')
    {
        fdf->flag = 1;
        handle_error(ERO_NAME_FILE);
        return ;
    }
}

int get_row_length(char *line, t_data *fdf)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (!ft_isdigit(line[i]) && (line[i] != ' ' && line[i] != '-' && line[i] != '+'))
        {
            fdf->flag  = 4;
            return (++i);
        }
        if (line[i] != ' ' && line[i] != '-' && line[i] != '+')
        {
            count++;
            while (line[i + 1] != ' ' && line[i + 1])
            i++;
        }
        i++;
    }
    return (count);
}

int    q_get_dimensions(t_data *fdf, char *arg)
{
    char *line;
    int is_changed;
    int fd;
 
    is_changed = 0;
    fd = open(arg, O_RDONLY);
    if (fd == -1)
    {
        handle_error(ERO_OPEN_FILE);
        fdf->flag = 9;
        return (9);
    }
    line = get_next_line(fd);
    (fdf)->height++;
    while (line)
    {
        (fdf)->width  = get_row_length(line, fdf);
        if (is_changed != (fdf)->width && (fdf)->height != 1)
        {
            fdf->flag = 1;
            handle_error(ERO_MAP);
            return (fdf->flag);
        }
        is_changed = (fdf)->width;
        if (fdf->flag)
        {
            handle_error(ERO_MAP);
            write(2, "At line: ", 9);
            ft_putnbr_fd((fdf)->height, 2);
            write(2, "\nAt column: ", 13);
            ft_putnbr_fd((fdf)->width, 2);
            fdf->flag  = 9;
            return (fdf->flag);

        }
        line = get_next_line(fd);
        (fdf)->height++;
    }
    free(line);
    close(fd);
    return (0);  
}

void    set_map(t_data *fdf, char *arg)
{
    int x;
    int y;
    int fd;
    char *line;
    char **split;

    y = -1;
    fdf->map = (t_map **)malloc(sizeof(t_map *) * fdf->height);
    fd = open(arg, O_RDONLY);
    if (fd == -1)
    {
        handle_error(ERO_OPEN_FILE);
        return ;
    }
    while (++y < fdf->height)
    {
        fdf->map[y] = (t_map *)malloc(sizeof(t_map) * fdf->width);
        line = get_next_line(fd);
        if (!line)
            break;
        split = ft_split(line, ' ');
        if (!split)
        {
            free(line);
            break;
        }
        x = -1;
        while (++x < fdf->width)
        {
            fdf->map[y][x].x = x;
            fdf->map[y][x].y = y;
            fdf->map[y][x].z = ft_atoi(split[x]);
        }
        frees_split(split);
        free(line);
    }
    close(fd);
}

void print_map(t_data *fdf)
{
    int y;
    int x;

    for (y = 0; y < fdf->height; y++)
    {
        for (x = 0; x < fdf->width; x++)
        {
            printf("%d ", fdf->map[y][x].z);
            if (fdf->map[y][x].z <= 0 && fdf->map[y][x+1].z <= 0)
                printf(" ");
            if (fdf->map[y][x].z > 0 && fdf->map[y][x+1].z <= 0)
                printf(" ");
        }
        printf("\n");
    }
}

int    setup_fdf(t_data *fdf, char *arg)
{
    (fdf)->height = 0;
    (fdf)->width = 0;
    fdf->flag = 0;

    check_name(arg, fdf);
    if (fdf->flag)
        return fdf->flag;
    q_get_dimensions(fdf, arg);
    if (fdf->flag)
        return fdf->flag;
    if (!(fdf->flag))
        write(1, "Map is valid\n", 13);
    set_map(fdf, arg);
    print_map(fdf);
    frees(fdf);
    return fdf->flag;
}