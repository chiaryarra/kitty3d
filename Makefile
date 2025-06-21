NAME = cub3d

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

MLXFLAGS = -lmlx_Linux -L./minilibx-linux -lXext -lX11 -lm

LIB = includes/libft/libft.a

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C includes/libft
	make -C minilibx-linux
	$(CC) $(MLXFLAGS) $(OBJS) -o $(NAME) $(LIB)

.c.o:
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C includes/libft
	make clean -C minilibx-linux
	rm -f $(OBJS)

fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

re: fclean $(NAME)