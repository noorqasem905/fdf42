CC =  cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = fdf
SRCS = src/fdf.c 					\
		src/read_map.c 				\
		src/setup_window.c 			\
		src/draw_map.c 				\
		src/bresenham_algorithm.c 	\
		src/draw_line.c 			\
		src/utils.c					\
		src/fdf_handling.c

all: $(NAME)

OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME) -Llibft -lft -g

clean:
	make -C libft clean
	rm -f $(OBJS)
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
