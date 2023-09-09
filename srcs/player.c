/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:06:11 by minabe            #+#    #+#             */
/*   Updated: 2023/09/09 20:04:10 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_nowall(t_game *game, int direction);
static void	init_vectors(t_player *player, char c);

void	init_player(t_game *game)
{
	int	i;
	int	j;
	char	**map;

	map = game->map->map;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				set_vector(&game->player.pos, i, j);
				init_vectors(&game->player, map[i][j]);
			}
			j++;
		}
		i++;
	}
}

static void	init_vectors(t_player *player, char c)
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

void	set_position(t_game *game, int direction)
{
	if (direction == UP && check_nowall(game, direction))
		game->player.pos.y++;
	else if (direction == DOWN && check_nowall(game, direction))
		game->player.pos.y--;
	else if (direction == LEFT && check_nowall(game, direction))
		game->player.pos.x--;
	else if (direction == RIGHT && check_nowall(game, direction))
		game->player.pos.x++;
}

static bool	check_nowall(t_game *game, int direction)
{
	int	x;
	int	y;

	if (direction == UP || direction == DOWN)
	{
		x = (int)game->player.pos.x;
		if (direction == UP)
			y = (int)game->player.pos.y + 1;
		else
			y = (int)game->player.pos.y - 1;
	}
	if (direction == LEFT || direction == RIGHT)
	{
		y = (int)game->player.pos.y;
		if (direction == LEFT)
			x = (int)game->player.pos.x - 1;
		else
			x = (int)game->player.pos.x + 1;
	}
	if (game->map->map[x][y] == '1')
		return (false);
	return (true);
}
