CC =  cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = fdf
SRCS = src/fdf.c src/read_map.c src/setup_window.c src/bresenham_algorithm.c src/draw_map.c

all: $(NAME)

OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS)
	make -C libft
	$(CC)  $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME) -Llibft -lft -g

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Lminilibx-linux -O3 -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
