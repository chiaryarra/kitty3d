NAME = cub3d

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

MLXFLAGS = -lmlx_Linux -L./includes/minilibx-linux -lXext -lX11 -lm

LIB = includes/libft/libft.a

SRCS = srcs/misc/kitty3d.c \
srcs/parser/handle_map.c \
srcs/parser/validation_utils.c \
srcs/misc/error_utils.c \
srcs/misc/general_utils.c \
srcs/parser/set_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C includes/libft
	make -C includes/minilibx-linux
	$(CC) $(MLXFLAGS) $(OBJS) -o $(NAME) $(LIB)

.c.o:
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C includes/libft
	make clean -C includes/minilibx-linux
	rm -f $(OBJS)

fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

re: fclean $(NAME)