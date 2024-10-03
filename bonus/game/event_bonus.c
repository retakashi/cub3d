/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:54:49 by minabe            #+#    #+#             */
/*   Updated: 2024/10/03 10:05:27 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	deal_key(int keycode, t_game *game)
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
		set_field_of_view(&game->player, M_PI / ROT_INTERVAL);
	if (keycode == KEY_RIGHT)
		set_field_of_view(&game->player, -M_PI / ROT_INTERVAL);
	return (EXIT_SUCCESS);
}

int	mouse_move(int x, int y, t_game *game)
{
	int			center_x;
	t_vector	pos;

	(void)y;
	center_x = WIN_WIDTH / 2;
	pos.x = x - center_x;
	set_field_of_view(&game->player, M_PI / ROT_INTERVAL * (-pos.x / center_x));
	return (EXIT_SUCCESS);
}
