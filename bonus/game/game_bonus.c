/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:15:29 by minabe            #+#    #+#             */
/*   Updated: 2024/10/03 10:13:00 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_game(t_game *game, t_map *map, t_header *header);
static void	loop_game(t_game *game);

void	start_game(t_map *map, t_header *header)
{
	t_game	game;
	t_image	img;

	init_game(&game, map, header);
	game.win_ptr = mlx_new_window(game.ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (game.win_ptr == NULL)
		ft_error("Mlx window init failed.");
	img.img = mlx_new_image(game.ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	game.img = &img;
	loop_game(&game);
	return ;
}

static void	init_game(t_game *game, t_map *map, t_header *header)
{
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed.");
	game->map = map;
	init_player(game);
	add_textures(game, header);
}

static void	loop_game(t_game *game)
{
	mlx_loop_hook(game->ptr, draw_window, game);
	mlx_hook(game->win_ptr, ON_KEYDOWN, 1L << 0, deal_key, game);
	mlx_hook(game->win_ptr, ON_DESTROY, DEFAULT, end_game, game);
	mlx_hook(game->win_ptr, ON_MOUSEMOVE, 1L<<6, mouse_move, game);
	mlx_loop(game->ptr);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win_ptr);
	remove_textures(game);
	exit(EXIT_SUCCESS);
}
