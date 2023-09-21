/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/09/19 22:53:17 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game(t_game *game, t_map *map, t_header *header);
static int	deal_key(int keycode, t_game *game);
static void	loop_game(t_game *game);

void	start_game(t_map *map, t_header *header)
{
	t_game	game;
	t_image	img;

	init_game(&game, map, header);
	game.win_ptr = mlx_new_window(game.ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (game.win_ptr == NULL)
		ft_error("Mlx window init failed");
	img.img = mlx_new_image(game.ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
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

static int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		end_game(game);
	if (keycode == KEY_W)
		set_position(game, FRONT);
	if (keycode == KEY_S)
		set_position(game, BACK);
	if (keycode == KEY_A)
		set_position(game, LEFT);
	if (keycode == KEY_D)
		set_position(game, RIGHT);
	if (keycode == KEY_LEFT)
		set_field_of_view(&game->player, ROTATE_SPEED);
	if (keycode == KEY_RIGHT)
		set_field_of_view(&game->player, -ROTATE_SPEED);
	return (EXIT_SUCCESS);
}

static void	loop_game(t_game *game)
{
	mlx_loop_hook(game->ptr, draw_window, game);
	mlx_hook(game->win_ptr, ON_KEYDOWN, 1L << 0, deal_key, game);
	mlx_hook(game->win_ptr, ON_DESTROY, DEFAULT, end_game, game);
	mlx_loop(game->ptr);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win_ptr);
	remove_textures(game);
	exit(EXIT_SUCCESS);
}
