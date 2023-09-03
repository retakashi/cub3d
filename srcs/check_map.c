/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/09/03 18:23:46 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_factors(t_map *map);
// static bool	check_wall(t_map *map);

/* wallのcheck関数入れるか?? */
bool	check_map(t_map *map)
{
	if (!check_factors(map))
	{
		printf("Error\n");
		printf("Invalid map.");
		return (false);
	}
	return (true);
}

static bool	check_factors(t_map *map)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	start = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'W' || map->map[i][j] == 'E')
				start++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != '\n' && map->map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	if (start != 1)
		return (false);
	return (true);
}

// static bool	check_wall(t_map *map)
// {
// 	size_t	i;

// 	i = 0;
// 	while (map->map[i] != '\0')
// 	{
// 		if (i < map->width || i > ft_strlen(map->map) - map->width)
// 		{
// 			if (map->map[i] != '1' && map->map[i] != '\n')
// 				return (false);
// 		}
// 		if (i % map->width == 0 || i % map->width == map->width - 2)
// 		{
// 			if (map->map[i] != '1')
// 				return (false);
// 		}
// 		i++;
// 	}
// 	return (true);
// }

bool	is_cub_file(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ft_strcmp(".cub", ext) != 0)
		return (false);
	return (true);
}
