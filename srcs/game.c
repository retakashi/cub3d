/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/09/05 15:39:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_game(t_game *game, t_map *map, t_header *header);
static int	deal_key(int keycode, t_game *game);

void	start_game(t_map *map, t_header *header)
{
	t_game	game;

	init_game(&game, map, header);
	game.win_ptr = mlx_new_window(game.ptr, game.width, game.height, "cub3d");
	if (game.win_ptr == NULL)
		ft_error("Mlx window init failed");
	// mlx_loop_hook(game.ptr, print_window, &game);
	mlx_key_hook(game.win_ptr, deal_key, &game);
	mlx_hook(game.win_ptr, 17, 0, end_game, &game);
	mlx_loop(game.ptr);
	return ;
}

static void	init_game(t_game *game, t_map *map, t_header *header)
{
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed.");
	game->map = map;
	init_player(game);
	printf("[init]\n%f %f\n", game->player.pos.x, game->player.pos.y);
	(void)header;
	// game->wall->north_texture = header->north_texture_path;
	// game->wall->south_texture = header->south_texture_path;
	// game->wall->east_texture = header->east_texture_path;
	// game->wall->west_texture = header->west_texture_path;
	game->width = 1000;
	game->height = 1000;
}

static int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		end_game(game);
	if (keycode == KEY_W)
		set_position(game, UP);
	if (keycode == KEY_S)
		set_position(game, DOWN);
	if (keycode == KEY_A)
		set_position(game, LEFT);
	if (keycode == KEY_D)
		set_position(game, RIGHT);
	if (keycode == KEY_LEFT)
		printf("LEFT\n");
	if (keycode == KEY_RIGHT)
		printf("RIGHT\n");
	return (EXIT_SUCCESS);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
