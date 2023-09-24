/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:06:11 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 16:12:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool		check_nowall(t_game *game, t_vector pos);
static t_vector	calculate_new_position(t_game *game, int direction);
static void		init_field_of_view(t_player *player, char c);

void	init_player(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map->map;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (ft_strchr("NEWS", map[j][i]) != NULL)
			{
				set_vector(&game->player.pos, i, j);
				init_field_of_view(&game->player, map[j][i]);
			}
			i++;
		}
		j++;
	}
}

static void	init_field_of_view(t_player *player, char c)
{
	if (c == 'N')
	{
		set_vector(&player->dir, 0, 1);
		set_vector(&player->plane, 1, 0);
	}
	if (c == 'S')
	{
		set_vector(&player->dir, 0, -1);
		set_vector(&player->plane, -1, 0);
	}
	if (c == 'W')
	{
		set_vector(&player->dir, -1, 0);
		set_vector(&player->plane, 0, 1);
	}
	if (c == 'E')
	{
		set_vector(&player->dir, 1, 0);
		set_vector(&player->plane, 0, -1);
	}
}

void	set_field_of_view(t_player *player, double fov)
{
	t_vector	plane;
	t_vector	dir;

	plane = player->plane;
	dir = player->dir;
	set_vector(&dir, rotate_vec_x(dir, fov), rotate_vec_y(dir, fov));
	set_vector(&plane, rotate_vec_x(plane, fov), rotate_vec_y(plane, fov));
}

void	set_position(t_game *game, int direction)
{
	t_vector	new_pos;

	new_pos = calculate_new_position(game, direction);
	if (check_nowall(game, new_pos))
		set_vector(&game->player.pos, new_pos.x, new_pos.y);
}

static t_vector	calculate_new_position(t_game *game, int direction)
{
	t_vector	new_pos;

	if (direction == FRONT)
	{
		new_pos.x = game->player.pos.x + game->player.dir.x * MOVE_SPEED;
		new_pos.y = game->player.pos.y - game->player.dir.y * MOVE_SPEED;
	}
	if (direction == BACK)
	{
		new_pos.x = game->player.pos.x - game->player.dir.x * MOVE_SPEED;
		new_pos.y = game->player.pos.y + game->player.dir.y * MOVE_SPEED;
	}
	if (direction == LEFT)
	{
		new_pos.x = game->player.pos.x - game->player.dir.y * MOVE_SPEED;
		new_pos.y = game->player.pos.y - game->player.dir.x * MOVE_SPEED;
	}
	if (direction == RIGHT)
	{
		new_pos.x = game->player.pos.x + game->player.dir.y * MOVE_SPEED;
		new_pos.y = game->player.pos.y + game->player.dir.x * MOVE_SPEED;
	}
	return (new_pos);
}

static bool	check_nowall(t_game *game, t_vector pos)
{
	if (game->map->map[(int)pos.y][(int)pos.x] == '1')
		return (false);
	return (true);
}
