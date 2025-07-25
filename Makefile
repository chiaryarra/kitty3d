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
SRCS = cub3d_folder/srcs/misc/kitty3d.c \
cub3d_folder/srcs/misc/error_utils.c \
cub3d_folder/srcs/misc/general_utils.c \
cub3d_folder/srcs/misc/rgb_handling.c \
cub3d_folder/srcs/misc/free_utils.c \
cub3d_folder/srcs/misc/pixel_utils.c \
cub3d_folder/srcs/parser/handle_map.c \
cub3d_folder/srcs/parser/validation_utils.c \
cub3d_folder/srcs/parser/set_utils.c \
cub3d_folder/srcs/parser/handle_grid.c \
cub3d_folder/srcs/parser/map_grid_utils.c \
cub3d_folder/srcs/parser/player_utils.c \
cub3d_folder/srcs/parser/grid_utils.c \
cub3d_folder/srcs/raycast/keys.c \
cub3d_folder/srcs/raycast/collision.c \
cub3d_folder/srcs/raycast/init_engine.c \
cub3d_folder/srcs/raycast/raycast.c \
cub3d_folder/srcs/raycast/render_frame.c \
cub3d_folder/srcs/raycast/set_raycast.c \
cub3d_folder/srcs/raycast/render_textures.c

# Objetos .o dos arquivos a compilar
OBJS = $(SRCS:.c=.o)

# Fontes do arquivos .c da parte bônus para compilar

BONUS_SRCS = 

# Objetos .o dos arquivos da parte bônus a compilar

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Regra padrão: compila MLX, libft e binário principal
all: $(NAME)

# Linka o executável com os objetos e libft, mlx e do projeto
$(NAME): $(OBJS)
	make -C libs/libft
	make -C libs/minilibx-linux
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(MLXFLAGS)

# Regra genérica de compilação de cada .c como um .o
.c.o:
	$(CC) $(CFLAGS) -O3 -c $< -o $@

# Limpa todos os objetos .o do projeto, libft e minilibx 
clean:
	make clean -C libs/libft
	make clean -C libs/minilibx-linux
	rm -f $(OBJS) $(BONUS_OBJS)

# Limpa tudo: objetos + executáveis
fclean: clean
	make fclean -C libs/libft
	rm -f $(NAME) $(BONUS_NAME)

# Rebuild completo
re: fclean $(NAME)

bonus: $(BONUS_OBJS)
	rm $(NAME)
	$(CC) $(OBJS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIB) $(MLXFLAGS)