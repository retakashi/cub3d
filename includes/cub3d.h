/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/09/13 14:33:34 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <limits.h>
# include <float.h>
# include <stdarg.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "trigonometric.h"
# include "libft.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define WALL_HEIGHT 50

# define SIZE 64
# define WIDTH 1280
# define HEIGHT 960

# define ROTATE_SPEED 0.1
# define MOVE_SPEED 0.2

# define DEBUG 1
# define HEADER_LEN 6

# define DEFAULT 0

# define FISH_EYE_EFFECT 0

enum e_direction
{
	FRONT = 1,
	BACK = 2,
	LEFT = 10,
	RIGHT = 20,
};

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		items;
}	t_map;

typedef struct s_header
{
	char	*east_texture_path;
	char	*west_texture_path;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*ceiling_color;
	char	*floor_color;
}	t_header;

typedef struct s_wall
{
	void	*east_texture;
	void	*west_texture;
	void	*north_texture;
	void	*south_texture;
}	t_wall;

// 視野角90で固定
typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_image{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_game
{
	void		*ptr;
	void		*win_ptr;
	t_wall		*wall;
	int			ceiling_color;
	int			floor_color;
	t_player	player;
	t_map		*map;
	t_image		*img;
	int			wall_height;
}	t_game;

typedef struct s_ray
{
	int			x;
	t_vector	pos;
	t_vector	dir;
	t_vector	side_distance;
	t_vector	delta_distance;
	t_vector	step;
	t_vector	map;
	int			side;
	bool		hit;
	double		perpendicular_wall_distance;
}	t_ray;

bool		is_cub_file(char *filename);
size_t		count_map_width(char *map);
int			count_map_height(char **file);
bool		check_map(t_map *map);
void		get_file(char *file, t_map *map, t_header *header);

void		start_game(t_map *map, t_header *header);
int			end_game(t_game *game);

void		init_player(t_game *game);

void		set_position(t_game *game, int direction);
void		set_field_of_view(t_player *player, double fov);

void		set_vector(t_vector *vector, double x, double y);

void		calculate_ray(t_game *game, t_ray *ray);

int			draw_window(t_game *game);

double		vectorlen(t_vector vector);
void		init_header(t_game *game, t_header *header);;

#endif
