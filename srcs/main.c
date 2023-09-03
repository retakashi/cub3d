/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/09/03 18:36:13 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	cub3d(char *file);
static void	start_game(t_map *map, t_header *header);

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("No map file.");
	if (!is_cub_file(argv[1]))
		ft_error("Not a .cub file.");
	cub3d(argv[1]);
	return (0);
}

static void	cub3d(char *file)
{
	t_map		map;
	t_header	header;

	get_file(file, &map, &header);
	if (DEBUG)
	{
		puts("[map]");
		for (int i = 0; map.map[i] != NULL; i++)
			ft_printf("%s\n", map.map[i]);
	}
	if (!check_map(&map))
		exit(EXIT_FAILURE); // freeする？？
	start_game(&map, &header);
	return ;
}

static void	start_game(t_map *map, t_header *header)
{
	t_game	game;

	init_game(&game, map, header);
	game.win_ptr = mlx_new_window(game.ptr, game.width, game.height, "cub3d");
	if (game.win_ptr == NULL)
		ft_error("Mlx window init failed");
	// mlx_loop_hook(game.ptr, print_window, game);
	mlx_key_hook(game.win_ptr, deal_key, &game);
	mlx_hook(game.win_ptr, 17, 0, end_game, &game);
	mlx_loop(game.ptr);
	return ;
}
