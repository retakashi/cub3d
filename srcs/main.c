/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 16:31:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub3d(char *file);

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q cub3D");
// }

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
	if (!check_map(&map))
		exit(EXIT_FAILURE);
	start_game(&map, &header);
	return ;
}
