/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:19:54 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/08 16:00:03 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_node	t_map;
typedef struct s_data	t_data;
# define HEIGHT 1000
# define WIDTH 1200
# define PI 3.14159
# define cos_x cos(1.1)
# define sin_y sin(0.5) 
# define ESC 65307
# define SPACE 32
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
	char				*addr;
	void				*img;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					height;
	int					width;
	int					zoom;
	int					flag;
	int					press;
	t_map				**map;
};
struct					s_node
{
	int					x;
	int					y;
	int					z;
	int					i;
	int					j;
	int					color;
};

void					frees(t_data *root);
void					frees_split(char **root);
void					check_name(char *arg, t_data *fdf);
void					set_pixel(t_data *fdf, int x, int y, int color);
void					slope_less_then_one(int dx, int dy, t_map *a, t_data *fdf);
void					setup_row(t_data *fdf, int pixel_x, float *pixel, int i, int j, t_map *a);
void					setup_column(t_data *fdf, int pixel_y, float *pixel, int i, int j, t_map *a);
void					handle_error(char *_error);
void					slope_greater_then_one(int dx, int dy, t_map *a, t_data *fdf);
void					set_row(t_data *fdf, int pixel_x, int pixel_y, t_map *a);
void					set_column(t_data *fdf, int pixel_x, int pixel_y, t_map *a);
int						q_get_dimensions_handling(t_data *fdf, int *is_changed);
int						close_d(int keycode, t_data *fdf);
int						destroy_image(int keycode, t_data *fdf);
int						get_row_length(char *line, t_data *flag);
int						sset_algo(t_data *fdf);
int						q_get_dimensions(t_data *fdf, char *arg);
int						setup_fdf(t_data *fdf, char *arg);
int						close_by_cross(t_data *fdf);
void					set_map(t_data *fdf, char *arg);
void					draw_map(t_data *fdf, t_map *a);
void					setup_win(t_data *fdf);

#endif
