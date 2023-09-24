/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:01:30 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 17:09:35 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vector	calculate_new_position(t_game *game, int direction);
static bool		check_nowall(t_game *game, t_vector pos);

void	set_field_of_view(t_player *player, double fov)
{
	set_vector(&player->dir, rotate_vec_x(player->dir, fov), \
			rotate_vec_y(player->dir, fov));
	set_vector(&player->plane, rotate_vec_x(player->plane, fov), \
			rotate_vec_y(player->plane, fov));
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
