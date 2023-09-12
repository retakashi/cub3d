/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:06:11 by minabe            #+#    #+#             */
/*   Updated: 2023/09/12 20:07:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static bool	check_nowall(t_game *game, int direction);
static void	init_field_of_view(t_player *player, char c);

void	init_player(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map->map;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("NEWS", map[i][j]) != NULL)
			{
				set_vector(&game->player.pos, i, j);
				init_field_of_view(&game->player, map[i][j]);
			}
			j++;
		}
		i++;
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
	// printf("[direction]\nx: %f, y: %f\n", player->dir.x, player->dir.y);
}

void	set_position(t_game *game, int direction)
{
	if (direction == FRONT)
		set_vector(&game->player.pos, game->player.pos.x - game->player.dir.x * MOVE_SPEED, game->player.pos.y - game->player.dir.y * MOVE_SPEED);
	else if (direction == BACK)
		set_vector(&game->player.pos, game->player.pos.x + game->player.dir.x * MOVE_SPEED, game->player.pos.y - game->player.dir.y * MOVE_SPEED);
	else if (direction == LEFT)
		set_vector(&game->player.pos, game->player.pos.x - game->player.dir.y * MOVE_SPEED, game->player.pos.y + game->player.dir.x * MOVE_SPEED);
	else if (direction == RIGHT)
		set_vector(&game->player.pos, game->player.pos.x + game->player.dir.y * MOVE_SPEED, game->player.pos.y - game->player.dir.x * MOVE_SPEED);
	printf("[pos]\nx: %f, y: %f\n", game->player.pos.x, game->player.pos.y);
}

// static bool	check_nowall(t_game *game, int direction)
// {
// 	int	x;
// 	int	y;

// 	if (direction == FRONT || direction == BACK)
// 	{
// 		y = (int)game->player.pos.y;
// 		if (direction == FRONT)
// 			x = (int)game->player.pos.x - 1;
// 		else
// 			x = (int)game->player.pos.x + 1;
// 	}
// 	if (direction == LEFT || direction == RIGHT)
// 	{
// 		x = (int)game->player.pos.x;
// 		if (direction == LEFT)
// 			y = (int)game->player.pos.y - 1;
// 		else
// 			y = (int)game->player.pos.y + 1;
// 	}
// 	if (game->map->map[x][y] == '1')
// 		return (false);
// 	return (true);
// }
