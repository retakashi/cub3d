/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/09/05 18:07:50 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <errno.h>
# include <mlx.h>
# include "libft.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define SIZE 32
# define WIDTH 1000
# define HEIGHT 1000

# define DEBUG 1
# define HEADER_LEN 6

enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
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

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

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

typedef struct s_game
{
	void		*ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_wall		*wall;
	t_player	player;
	t_map		*map;
}	t_game;

bool		is_cub_file(char *filename);
size_t		count_map_width(char *map);
int			count_map_height(char **file);
bool		check_map(t_map *map);
void		get_file(char *file, t_map *map, t_header *header);

void		start_game(t_map *map, t_header *header);
int			end_game(t_game *game);

void		init_player(t_game *game);
void		set_position(t_game *game, int direction);

void		set_vector(t_vector *vector, double x, double y);

#endif
