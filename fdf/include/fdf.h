/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:19:54 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/03 23:09:16 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_node	t_map;
typedef struct s_data	t_data;
# define HEIGHT 900
# define WIDTH 1200
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
# define ESC 65307

struct					s_data
{
	void				*img;
	void				*mlx_init;
	void				*mlx_win;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					zoom;
	int					pixel;
	int					height;
	int					width;
	int					flag;
	t_map				**map;
};
struct					s_node
{
	int					x;
	int					y;
	int					z;
	int					color;
};

void					frees(t_data *root);
void					set_pixel(t_data *fdf, int x, int y, int color);
void					slope_less_then_one(int dx, int dy, t_map *a, t_map *b, t_data *fdf);
void					handle_error(char *_error);
void					slope_greater_then_one(int dx, int dy, t_map *a,
	t_map *b, t_data *fdf);
	int						close_d(int keycode, t_data *fdf);
	int						destroy_image(int keycode, t_data *fdf);
void					check_name(char *arg, t_data *fdf);
int						get_row_length(char *line, t_data *flag);
int						sset_algo(t_data *fdf);
int						q_get_dimensions(t_data *fdf, char *arg);
int						setup_fdf(t_data *fdf, char *arg);
void					set_map(t_data *fdf, char *arg);
void					draw_map(t_data *fdf, int x, int y, int color, int z);
void					setup_win(t_data *fdf);

#endif
