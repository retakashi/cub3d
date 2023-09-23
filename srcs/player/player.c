/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:06:11 by minabe            #+#    #+#             */
/*   Updated: 2023/09/23 23:34:06 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_nowall(t_game *game, int direction);
static void	init_field_of_view(t_player *player, char c);

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
	set_vector(&player->dir, rotate_vec_x(player->dir, fov), rotate_vec_y(player->dir, fov));
	set_vector(&player->plane, rotate_vec_x(player->plane, fov), rotate_vec_y(player->plane, fov));
}

void	set_position(t_game *game, int direction)
{
	if (direction == FRONT && check_nowall(game, FRONT))
		set_vector(&game->player.pos, game->player.pos.x + game->player.dir.x * MOVE_SPEED, game->player.pos.y - game->player.dir.y * MOVE_SPEED);
	else if (direction == BACK && check_nowall(game, BACK))
		set_vector(&game->player.pos, game->player.pos.x - game->player.dir.x * MOVE_SPEED, game->player.pos.y + game->player.dir.y * MOVE_SPEED);
	else if (direction == LEFT  && check_nowall(game, LEFT))
		set_vector(&game->player.pos, game->player.pos.x - game->player.dir.y * MOVE_SPEED, game->player.pos.y - game->player.dir.x * MOVE_SPEED);
	else if (direction == RIGHT && check_nowall(game, RIGHT))
		set_vector(&game->player.pos, game->player.pos.x + game->player.dir.y * MOVE_SPEED, game->player.pos.y + game->player.dir.x * MOVE_SPEED);
}

static bool	check_nowall(t_game *game, int direction)
{
	double	x;
	double	y;

	if (direction == FRONT)
	{
		x = game->player.pos.x + game->player.dir.x * MOVE_SPEED;
		y = game->player.pos.y - game->player.dir.y * MOVE_SPEED;
	}
	if (direction == BACK)
	{
		x = game->player.pos.x - game->player.dir.x * MOVE_SPEED;
		y = game->player.pos.y + game->player.dir.y * MOVE_SPEED;
	}
	if (direction == LEFT)
	{
		x = game->player.pos.x - game->player.dir.y * MOVE_SPEED;
		y = game->player.pos.y - game->player.dir.x * MOVE_SPEED;
	}
	if (direction == RIGHT)
	{
		x = game->player.pos.x + game->player.dir.y * MOVE_SPEED;
		y = game->player.pos.y + game->player.dir.x * MOVE_SPEED;
	}
	if (game->map->map[(int)y][(int)x] == '1')
		return (false);
	return (true);
}
