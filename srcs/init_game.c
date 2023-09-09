/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:24:58 by minabe            #+#    #+#             */
/*   Updated: 2023/09/09 15:34:24 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_header(t_game *game, t_header *header);

void	init_game(t_game *game, t_map *map, t_header *header)
{
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed.");
	game->map = map;
	init_player(game);
	init_header(game, header);
}

static int	create_rgb(char *rgb)
{
	char	**colors;
	int		r;
	int		g;
	int		b;
	int		i;

	colors = ft_split(rgb, ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	i = 0;
	while (i < 3)
	{
		ft_free(colors[i]);
		i++;
	}
	ft_free(colors);
	return (r << 16 | g << 8 | b);
}

static void	init_header(t_game *game, t_header *header)
{
	game->ceiling_color = create_rgb(header->ceiling_color);
	game->floor_color = create_rgb(header->floor_color);
}
