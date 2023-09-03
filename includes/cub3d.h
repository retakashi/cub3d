/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/09/03 17:40:19 by minabe           ###   ########.fr       */
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
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define SIZE 32

# define DEBUG 1
# define HEADER_LEN 6
enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
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
	size_t	x;
	size_t	y;
}	t_vector;



bool		is_cub_file(char *filename);
size_t		count_map_width(char *map);
int			count_map_height(char **file);
bool		check_map(t_map *map);
void		get_file(char *file, t_map *map, t_header *header);

bool		check_reach_objs(t_map *mp);

#endif
