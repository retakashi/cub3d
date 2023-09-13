/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/09/13 20:00:36 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_factors(t_map *map);
static bool	check_wall(t_map *map);

bool	check_map(t_map *map)
{
	if (!check_factors(map) || !check_wall(map))
	{
		printf("Error\n");
		printf("Invalid map.");
		return (false);
	}
	return (true);
}

static bool	check_wall(t_map *map)
{
	(void)map;
	return (true);
}

static bool	check_factors(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'W' || map->map[i][j] == 'E')
				player++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != '\n' && map->map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}

bool	is_cub_file(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ft_strcmp(".cub", ext) != 0)
		return (false);
	return (true);
}
