/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/09/03 15:50:47 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_factors(char *map);
// static bool	check_wall(t_map *map);

bool	check_map(char *map)
{
	if (!check_factors(map))
	{
		ft_printf("Error\n");
		if (!check_factors(map))
			ft_printf("Invalid map.");
		// else if (!check_wall(map))
		// 	ft_printf("Incorrect walls placement.");
		// else
		// 	ft_printf("Cannot reach all objects.");
		return (false);
	}
	return (true);
}

static bool	check_factors(char *map)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
			start++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n' && map[i] != ' ')
			return (false);
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
