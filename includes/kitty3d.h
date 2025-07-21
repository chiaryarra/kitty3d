/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:36:07 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/21 15:58:31 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KITTY3D_H
# define KITTY3D_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_STEP   0.1
# define ROT_ANGLE   0.05
# define COLLISION_RAY 0.1
# define FOV_RANGE 0.66

typedef int t_bool;

enum	e_errors {
	WRONG_FILENAME,
	OPEN_ERROR,
	EMPTY_FILE,
	INVALID_CONFIG,
	INDENTED_CONFIG,
	INVALID_FLOOR_COORDS,
	INVALID_CEIL_COORDS,
	INVALID_TEXTURE_CONFIG,
	REPEATED_FLOOR_CONFIG,
	REPEATED_CEIL_CONFIG,
	REPEATED_TEXTURE_CONFIG,
	INVALID_MAP_CONTENT,
	MAP_EMPTY_LINE,
	REPEATED_STARTING_DIRECTION,
	MISSING_CONFIGS,
	MISSING_START_DIRECTION,
	GRID_ERROR,
	MALLOC_ERROR,
	MLX_INIT_ERROR,
	MLX_WINDOW_ERROR,
	MLX_IMAGE_ERROR
};

enum	e_keycodes {
	LEFT = 65361,
	UP = 65362,
	RIGHT = 65363,
	DOWN = 65364,
	A = 97,
	W = 119,
	S = 115,
	D = 100,
	ESC = 65307
};

enum	e_configs {
	FLOOR = 1,
	CEILING,
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_img
{
   void	*img;
   char	*addr;
   int	bpp;
   int	line;
   int	endian;
   int	width;
   int	height;
}   t_img;

typedef struct	s_mlx {
	void	*mlx;
	void	*window;
	t_img	*textures;
	t_img	main_img;
}	t_mlx;

typedef struct	s_rays {
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	impact_x;
	double	impact_y;
	int		line_h;
	int		draw_start;
	int		draw_end;
	t_bool	wall_hit;
	t_bool	wall_is_horizontal;
	int		wall_side_hit;
	double	wall_hit_point;
} t_rays;

typedef struct	s_raycast {
	double	pos_x;
	double	pos_y;
	double	pov_x;
	double	pov_y;
	double	plane_x;
	double	plane_y;
	double	temp_x;
	double	temp_y;
	double	move_vect;
	t_rays	*ray;
}	t_raycast;

typedef struct	s_map {
	char	*map;
	char	**grid;
	char	*map_string;
	int		grid_x_size;
	int		grid_y_size;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		start_direction;
	int		floor_color;
	int		floor_color_is_set;
	int		ceiling_color;
	int		ceiling_color_is_set;
	int		map_configs_set;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_data {
	t_map		*map;
	t_raycast	*raycast;
	t_mlx		*mlx;
}	t_data;


// Map reading 

char	*open_map(char *map_name);
char	*read_map(int fd);
t_map	*parse_map(char	*map_file);
void	set_map_configs(t_map *map, char *map_file, int *i);
void	set_floor(t_map *map, char *map_file, int *i);
void	set_ceiling(t_map *map,char *map_file, int *i);
void	set_texture(t_map *map, char *map_file, int *i, int texture_type);
void	set_map_grid(t_map *map, char *map_file, int *i);
int		get_grid_x_size(char **grid);
int		get_grid_y_size(char *map_string);
int		get_player_x(t_map *map);
int		get_player_y(t_map *map);
void	verify_grid(t_map *map, char **grid);

// Mlx and raycasting handling

void		put_pixel(t_data *d, int x, int y, int color);
void		draw_rays(t_data *d, int x, int color);
void 		render_frame(t_data *data);
int			key_press(int key, t_data *data);
int			close_window(void *pointer);
t_raycast	*create_starting_position(t_data *data);
void		init_engine(t_data *data);
void		cast_rays(t_data *d);
int			can_move_front_back(t_data *d, double x, double y, double move_vect);
int			can_move_side(t_data *d, double x, double y, double move_vector);
void		set_wall_hit_direction(t_raycast *raycast);

// Validations

int		map_name_validation(char *map_name);
int		verify_coord(char *cords, int *i);
int		verify_texture(t_map *map, int texture_type);
int		validate_colorcoords(char *cords);
int		validate_texture(char *texture_name);

// Error Utils

void	read_error(int error_type);
void	parse_error(int error_type, t_map *map);
void	texture_error(int error_type, t_map *map, int texture_type);
void	map_error(int error_type, t_map *map);
void	general_errors(int error_type, t_data *data);

// Free Utils 

void	free_mlx(t_mlx *mlx);
void	free_map(t_map *map);
void	free_all(t_data *data);

// Utils

int		is_kitty3dconfig(char *c, int *i);
int		config_len(int config_value);
int		hexmap_atoi(char *str, int *i);
int		rgb_to_int(char *floor_rgbcode);
char	*generate_texture_text(int texture_type);
int		is_map_direction(char c);
char	*fill_line(int lenght_of_line);

#endif