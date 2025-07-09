# Nome do executável principal e do bonus
NAME        = cub3d
BONUS_NAME  = cub3d_bonus

# Compilador e flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Includes e libs do MiniLibX/Linux e X11
CPPFLAGS    = -I includes -I includes/minilibx-linux
LDFLAGS     = -L includes/minilibx-linux -lmlx_Linux -lXext -lX11 -lm

# Diretório da MiniLibX
MLX_DIR     = includes/minilibx-linux

# Fontes stub
SRCS        = \
    srcs/main.c \
    srcs/test_map.c \
    srcs/init_engine.c \
    srcs/render_frame.c \
    srcs/keys.c \
    srcs/close_window_stub.c \
    srcs/pixel_utils.c \
	srcs/exit_with_error.c \
	srcs/raycast.c \
	srcs/colision.c 

OBJS        = $(SRCS:.c=.o)

# Alvos “virtuais”
.PHONY: all bonus clean fclean re

# Regra padrão: compila MLX e o binário principal
all: mlx $(NAME)

# Regra para o “bonus”: produz um executável separado
bonus: mlx $(BONUS_NAME)

# Compila a MiniLibX (se ainda não foi feita)
mlx:
	make -C $(MLX_DIR)

# Linka o executável principal
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Linka o executável de bonus (ainda sem fontes extras)
$(BONUS_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) -o $(BONUS_NAME)

# Regra genérica de compilação de cada .c para .o
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Limpa objetos do projeto e da MLX
clean:
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

# Limpa tudo: objetos + executáveis
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

# Rebuild completo
re: fclean all
