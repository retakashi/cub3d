/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:14:03 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 00:42:29 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 
static size_t compare_len(char *str1, char *str2, char c)
{
	if(!ft_strchr(str2, c))
		return(0);
	return(ft_strlen(str1) < (size_t)(ft_strrchr(str2, c) - str2) + 1);
}

static void	flood_fill(char **map, int i, int j)
{
	if (i > 0)
	{
		if (map[i][0] == '0' || compare_len(map[i - 1],map[i],'0') > 0)
			ft_error("Invalid map.");	
	}
	if(map[i + 1] != NULL)
	{
		if (map[i][0] == '0' || compare_len(map[i + 1],map[i],'0') > 0)
			ft_error("Invalid map.");	
	}
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

static void is_valid_player_position(char **map, int i, int j)
{
	char c;
	
	c = map[i][j];
	if(map[i][j + 1] == '\0')
		ft_error("Invalid map.");	
	if (i > 0)
	{
		if (compare_len(map[i - 1],map[i], c) > 0)
			ft_error("Invalid map.");	
	}
	if(map[i + 1] != NULL)
	{
		if (compare_len(map[i + 1],map[i], c) > 0)
			ft_error("Invalid map.");	
	}	
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
			if(ft_strchr("NEWS",cpy[i][j]))
				is_valid_player_position(cpy, i, j);
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
