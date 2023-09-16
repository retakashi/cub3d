/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:14:03 by minabe            #+#    #+#             */
/*   Updated: 2023/09/16 21:03:38 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	flood_fill(char **map, int i, int j)
{
	if (ft_strchr("1x", map[i][j]))
		return ;
	if (map[i][j + 1] == '\0' || map[i + 1] == NULL || i == 0 || j == 0 || map[i][j] == ' ' || map[i + 1][j] == '1')
		ft_error("Invalid map.");
	map[i][j] = 'x';
	if (0 < i)
		flood_fill(map, i - 1, j);
	if (0 < j)
		flood_fill(map, i, j - 1);
	if (map[i + 1] != NULL)
		flood_fill(map, i + 1, j);
	if (map[i][j + 1] != '\0')
		flood_fill(map, i, j + 1);
}

bool	check_wall(t_map *map)
{
	int		i;
	int		j;
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
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (cpy[i][j] != '\0')
		{
			if (cpy[i][j] != ' ')
				flood_fill(cpy, i, j);
			j++;
		}
		i++;
	}
	free_2d(cpy);
	return (true);
}
