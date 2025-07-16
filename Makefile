# Nome do executável principal e do bonus
NAME = cub3d
BONUS_NAME = cub3d_bonus

# Compilador e flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Includes e linkers da MinilibX
MLXFLAGS = -lmlx_Linux -L./includes/minilibx-linux -lXext -lX11 -lm

# Include da libft
LIB = includes/libft/libft.a

# Diretório da MiniLibX
MLX_DIR = includes/minilibx-linux

# Fontes dos arquivos .c para compilar
SRCS = srcs/misc/kitty3d.c \
srcs/misc/error_utils.c \
srcs/misc/general_utils.c \
srcs/misc/rgb_handling.c \
srcs/misc/free_utils.c \
srcs/misc/pixel_utils.c \
srcs/parser/handle_map.c \
srcs/parser/validation_utils.c \
srcs/parser/set_utils.c \
srcs/parser/handle_grid.c \
srcs/parser/map_grid_utils.c \
srcs/parser/player_utils.c \
srcs/raycast/keys.c \
srcs/raycast/collision.c \
srcs/raycast/init_engine.c \
srcs/raycast/raycast.c \
srcs/raycast/render_frame.c \
srcs/raycast/set_raycast.c


# Objetos .o dos arquivos a compilar
OBJS = $(SRCS:.c=.o)

# Regra padrão: compila MLX, libft e binário principal
all: $(NAME)

# Linka o executável com os objetos e libft, mlx e do projeto
$(NAME): $(OBJS)
	make -C includes/libft
	make -C includes/minilibx-linux
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(MLXFLAGS)

# Regra genérica de compilação de cada .c como um .o
.c.o:
	$(CC) $(CFLAGS) -O3 -c $< -o $@

# Limpa todos os objetos .o do projeto, libft e minilibx 
clean:
	make clean -C includes/libft
	make clean -C includes/minilibx-linux
	rm -f $(OBJS)

# Limpa tudo: objetos + executáveis
fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

# Rebuild completo
re: fclean $(NAME)