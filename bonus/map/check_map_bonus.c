/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 17:24:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	check_factors(t_map *map);

bool	check_map(t_map *map)
{
	if (!check_factors(map) || !check_wall(map))
	{
		ft_error("Invalid map.");
		return (false);
	}
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
			if (ft_strchr("NEWS", map->map[i][j]))
				player++;
			else if (!ft_strchr("01 \n", map->map[i][j]))
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
