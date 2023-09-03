/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/09/03 18:35:36 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_game *game, t_map *map, t_header *header)
{
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed.");
	game->map = map;
	(void)header;
	// game->wall->north_texture = header->north_texture_path;
	// game->wall->south_texture = header->south_texture_path;
	// game->wall->east_texture = header->east_texture_path;
	// game->wall->west_texture = header->west_texture_path;
	game->width = 1000;
	game->height = 1000;
}

int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		end_game(game);
	if (keycode == KEY_W)
		printf("W\n");
	if (keycode == KEY_A)
		printf("A\n");
	if (keycode == KEY_S)
		printf("S\n");
	if (keycode == KEY_D)
		printf("D\n");
	if (keycode == KEY_LEFT)
		printf("LEFT\n");
	if (keycode == KEY_RIGHT)
		printf("RIGHT\n");
	return (0);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
