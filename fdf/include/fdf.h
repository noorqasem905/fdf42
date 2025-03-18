/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:19:54 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/18 22:44:56 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node		t_map;
typedef struct s_data		t_data;
typedef struct s_control	t_control;
# define HEIGHT 1000
# define WIDTH 1200
# define PI 3.14159
# define COS_X 1.1
# define SIN_Y 0.5
# define ESC 65307
# define SPACE 32
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ZOOM_IN 65451
# define ZOOM_OUT 65453
# define ERO_NAME_FILE "Error : unsupported file"
# define ERO_OPEN_FILE "Error : failed to open file"
# define ERO_MAP "Error : map is invalid"
# define ERO_MALLOC "Error : malloc failed"
# define ERO_READ "Error : read failed"
# define ERO_FILE "The is not accessible or doesn't exist"
# define ERO_CLOSE "Error : close failed"
# define ERO_MLX "Error : mlx failed"
# define ERO_MLX_WIN "Error : mlx_new_window failed"
# define ERO_MLX_IMG "Error : mlx_new_image failed"
# define ERO_MLX_ADDR "Error : mlx_get_data_addr failed"
# define ERO_MLX_INIT "Error : mlx_init failed"

struct					s_data
{
	float				pixel;
	float				pixel_x;
	float				pixel_y;
	void				*mlx_init;
	void				*mlx_win;
	void				*img;
	int					*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					height;
	int					width;
	int					zoom;
	int					flag;
	float				press;
	int					tr;
	float				test;
	t_control			*control;
	t_map				**map;
};
struct					s_node
{
	float				x;
	float				y;
	float				z;
	int					i;
	int					j;
	int					color;
};
struct					s_control
{
	int					x;
	int					y;
	int					z;
	int					zoom;
	int					graph_rm;
};
void					slope_greater_then_one(int dx, int dy, t_map *a,
							t_data *fdf);
void					slope_less_then_one(int dx, int dy, t_map *a,
							t_data *fdf);
void					set_color(char	*split, t_data *fdf, int y, int x);
void					set_pixel(t_data *fdf, int x, int y, int color);
void					draw_map_utils(t_data *fdf, t_map *a);
void					check_name(char *arg, t_data *fdf);
void					set_map_utils(t_data *fdf, int fd);
void					set_column(t_data *fdf, t_map *a);
void					draw_map(t_data *fdf, t_map *a);
void					set_map(t_data *fdf, char *arg);
void					set_row(t_data *fdf, t_map *a);
void					handle_error(char *_error);
void					set_isometric(t_data *fdf);
void					frees_split(char **root);
void					setup_win(t_data *fdf);
void					frees(t_data *root);
int						q_get_dimensions_handling(t_data *fdf, int *is_changed);
int						slope(t_data *fdf, t_map *a, float x2, float y2);
int						setup_set_map(t_data *fdf, int fd, int y);
int						get_row_length(char *line, t_data *flag);
int						q_get_dimensions(t_data *fdf, char *arg);
int						destroy_image(int keycode, t_data *fdf);
int						close_d(int keycode, t_data *fdf);
int						setup_fdf(t_data *fdf, char *arg);
int						close_by_cross(t_data *fdf);
int						sset_algo(t_data *fdf);

#endif
