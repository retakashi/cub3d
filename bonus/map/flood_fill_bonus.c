/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:14:03 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 14:25:33 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	flood_fill(char **map, int i, int j)
{
	if (i < 0 || j < 0 || ft_strchr("1xNEWS", map[i][j]))
		return ;
	if (map[i][j] == ' ' || map[i][j + 1] == '\0' || map[i] == NULL)
		ft_error("Invalid map.");
	map[i][j] = 'x';
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j - 1);
	flood_fill(map, i + 1, j);
	flood_fill(map, i, j + 1);
}

char	**copy_map(t_map *map)
{
	int		i;
	char	**cpy;

	cpy = ft_calloc(sizeof(char *), (map->height + 1));
	if (cpy == NULL)
		ft_error("Malloc failed");
	i = 0;
	while (i < map->height)
	{
		cpy[i] = ft_strdup(map->map[i]);
		if (cpy[i] == NULL)
			ft_error("Malloc failed");
		i++;
	}
	return (cpy);
}

bool	check_wall(t_map *map)
{
	int		i;
	int		j;
	char	**cpy;

	cpy = copy_map(map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (cpy[i][j] != '\0')
		{
			if (cpy[i][j] == '0')
				flood_fill(cpy, i, j);
			j++;
		}
		i++;
	}
	if (DEBUG)
	{
		printf("\n[cpy]\n");
		for (int i = 0; cpy[i] != NULL; i++)
			printf("%s\n", cpy[i]);
	}
	free_2d(cpy);
	return (true);
}
