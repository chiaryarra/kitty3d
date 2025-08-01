/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:36:07 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/01 13:56:45 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KITTY3D_BONUS_H
# define KITTY3D_BONUS_H

# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

// Generic macros

# define TRUE 1
# define FALSE 0

// Game referent macros

# define MOVE_STEP   0.1
# define ROT_ANGLE   0.05
# define COLLISION_RAY 0.2
# define FOV_RANGE 0.66

// Bonus referent macros

# define MOUSE_SENSIBILITY 0.002

// Retypings

typedef int	t_bool;

// Errors enum

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

// Enum with the keycodes of the keyboard (could have been defined with #define too)

enum	e_keycodes {
	LEFT = 65361,
	UP = 65362,
	RIGHT = 65363,
	DOWN = 65364,
	A = 97,
	W = 119,
	S = 115,
	D = 100,
	SPACE = 32,
	ESC = 65307
};

// Enum with some macros used by the program

enum	e_configs {
	FLOOR = 1,
	CEILING,
	NORTH,
	SOUTH,
	EAST,
	WEST,
	DOOR
};

// Struct for vectors and coordinates

typedef struct s_vec {
	float	x;
	float	y;
}	t_vec;

// Struct with all the infos referent to the mlx_img pointer

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
}	t_img;

// Struct with all mlx referent data used by the program

typedef struct s_mlx {
	void	*mlx;
	void	*window;
	t_img	*textures;
	t_img	main_img;
	t_img	minimap;
	int		s_width;
	int		s_height;
	int		minimap_step_x;
	int		minimap_step_y;
	int		minimap_cs;
	int		minimap_cs_px;
	int		minimap_cs_py;
}	t_mlx;

// Struct with all data used by the cast_rays function

typedef struct s_rays {
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
	t_bool	door_hit;
	int		wall_side_hit;
	double	wall_hit_point;
	double	tex_step;
	int		tex_x;
	int		tex_y;
	double	tex_y_start;
}	t_rays;

// Struct with my basic double type data gathered from the map

typedef struct s_raycast {
	double		pos_x;
	double		pos_y;
	double		pov_x;
	double		pov_y;
	double		plane_x;
	double		plane_y;
	double		temp_x;
	double		temp_y;
	double		move_vect;
	t_rays		*ray;
}	t_raycast;

// Struct with the data gathered by the parser of the program

typedef struct s_map {
	char	*map;
	char	**grid;
	char	*map_string;
	int		grid_x_size;
	int		grid_y_size;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*door_texture;
	int		start_direction;
	int		floor_color;
	int		floor_color_is_set;
	int		ceiling_color;
	int		ceiling_color_is_set;
	int		map_configs_set;
	int		player_x;
	int		player_y;
}	t_map;

// Struct unifying everything

typedef struct s_data {
	t_map		*map;
	t_raycast	*raycast;
	t_mlx		*mlx;
}	t_data;

// Map reading 

char		*open_map_b(char *map_name);
char		*read_map_b(int fd);
t_map		*parse_map_b(char	*map_file);
void		set_map_configs_b(t_map *map, char *map_file, int *i);
void		set_floor_b(t_map *map, char *map_file, int *i);
void		set_ceiling_b(t_map *map, char *map_file, int *i);
void		set_texture_b(t_map *map, char *map_file, int *i, int texture_type);
void		set_map_grid_b(t_map *map, char *map_file, int *i);
int			get_grid_x_size_b(char **grid);
int			get_grid_y_size_b(char *map_string);
int			get_player_x_b(t_map *map);
int			get_player_y_b(t_map *map);
void		verify_grid_b(t_map *map, char **grid);
char		*clear_lines_b(char *map_file, int *i);
char		*recreate_grid_line_b(char *grid_line, int grid_x_size);

// Mlx and raycasting handling

void		put_pixel_b(t_data *d, int x, int y, int color);
void		draw_rays_b(t_data *d, int x, t_img texture);
void		check_to_draw_rays_b(t_data *d, int x);
void		render_frame_b(t_data *data);
int			key_press_b(int key, t_data *data);
int			close_window_b(void *pointer);
t_raycast	*create_starting_position_b(t_data *data);
void		init_engine_b(t_data *data);
void		cast_rays_b(t_data *d);
int			can_move_front_back_b(t_data *d, double x, \
double y, double move_vect);
int			can_move_side_b(t_data *d, double x, double y, double move_vector);
void		set_wall_hit_direction_b(t_raycast *raycast);
void		check_to_calculate_texture_positions_b(t_data *d);

// Validations

int			map_name_validation_b(char *map_name);
int			verify_coord_b(char *cords, int *i);
int			verify_texture_b(t_map *map, int texture_type);
int			validate_colorcoords_b(char *cords);
int			validate_texture_b(char *texture_name);

// Error Utils

void		read_error_b(int error_type);
void		parse_error_b(int error_type, t_map *map);
void		texture_error_b(int error_type, t_map *map, int texture_type);
void		map_error_b(int error_type, t_map *map);
void		general_errors_b(int error_type, t_data *data);

// Free Utils 

void		free_mlx_b(t_mlx *mlx);
void		free_map_b(t_map *map);
void		free_all_b(t_data *data);

// Utils

int			is_kitty3dconfig_b(char *c, int *i);
int			config_len_b(int config_value);
int			hexmap_atoi_b(char *str, int *i);
int			rgb_to_int_b(char *floor_rgbcode);
char		*generate_texture_text_b(int texture_type);
int			is_map_direction_b(char c);
char		*fill_line_b(int lenght_of_line);


// Bonus: Minimap

void		put_minimap_pixel_b(t_data *d, int x, int y, int color);
void		init_bonuses_b(t_data *d);
void		draw_minimap_b(t_data *d);
void		draw_cat_paw_b(t_data *d);

// Bonus: Mouse Movements

int			mouse_move_handler_b(int x, int y, t_data *d);

// Bonus: Door

void		open_close_door_b(t_data *d);

#endif