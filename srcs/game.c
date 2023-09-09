/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/09/09 15:07:47 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_game(t_game *game, t_map *map, t_header *header);
static int	deal_key(int keycode, t_game *game);

static void	loop_game(t_game *game)
{
	mlx_loop_hook(game->ptr, draw_window, game);
	// draw_window(game);
	mlx_hook(game->win_ptr, ON_KEYDOWN, DEFAULT, deal_key, game);
	mlx_hook(game->win_ptr, ON_DESTROY, DEFAULT, end_game, game);
	mlx_loop(game->ptr);
}

void	start_game(t_map *map, t_header *header)
{
	t_game	game;
	t_image	img;

	init_game(&game, map, header);
	game.win_ptr = mlx_new_window(game.ptr, game.width, game.height, "cub3d");
	if (game.win_ptr == NULL)
		ft_error("Mlx window init failed");
	img.img = mlx_new_image(game.ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.color = 0x00FF0000;
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
	printf("[init]\n%f %f\n", game->player.pos.x, game->player.pos.y);
	(void)header;
	// game->wall->north_texture = header->north_texture_path;
	// game->wall->south_texture = header->south_texture_path;
	// game->wall->east_texture = header->east_texture_path;
	// game->wall->west_texture = header->west_texture_path;
	game->width = WIDTH;
	game->height = HEIGHT;
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
	{
		set_vector(&game->player.dir, game->player.dir.x * cos(-ROTATE_SPEED) - game->player.dir.y * sin(-ROTATE_SPEED), game->player.dir.x * sin(-ROTATE_SPEED) + game->player.dir.y * cos(-ROTATE_SPEED));
		set_vector(&game->player.plane, game->player.plane.x * cos(-ROTATE_SPEED) - game->player.plane.y * sin(-ROTATE_SPEED), game->player.plane.x * sin(-ROTATE_SPEED) + game->player.plane.y * cos(-ROTATE_SPEED));
		game->img->color = 0x0000FF00;
	}
	if (keycode == KEY_RIGHT)
	{
		set_vector(&game->player.dir, game->player.dir.x * cos(ROTATE_SPEED) - game->player.dir.y * sin(ROTATE_SPEED), game->player.dir.x * sin(ROTATE_SPEED) + game->player.dir.y * cos(ROTATE_SPEED));
		set_vector(&game->player.plane, game->player.plane.x * cos(ROTATE_SPEED) - game->player.plane.y * sin(ROTATE_SPEED), game->player.plane.x * sin(ROTATE_SPEED) + game->player.plane.y * cos(ROTATE_SPEED));
		game->img->color = 0x000000FF;
	}
	return (EXIT_SUCCESS);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
