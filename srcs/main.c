/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/09/03 17:13:56 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	cub3d(char *file);

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
	// map.width = count_map_width(map.map); // 2次元で確保する必要あり？？
	// if (!check_map(&map))
	// {
	// 	ft_free(&map);
	// 	exit(EXIT_FAILURE);
	// }
	// start_game(&map);
	return ;
}

// static void	start_game(t_map *map)
// {
// 	t_game	*game;

// 	game = init_game(map);
// 	game->win_ptr = mlx_new_window(game->ptr, \
// 		game->width, game->height, "cub3d");
// 	if (game->win_ptr == NULL)
// 		ft_error("Mlx window init failed");
// 	mlx_loop_hook(game->ptr, print_window, game);
// 	mlx_key_hook(game->win_ptr, deal_key, game);
// 	mlx_hook(game->win_ptr, 17, 0, end_game, game);
// 	ft_printf("Game start!!\n");
// 	ft_printf("Pick up items and make the ghost come to life in his grave!\n");
// 	mlx_loop(game->ptr);
// 	return ;
// }
