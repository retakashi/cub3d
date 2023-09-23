/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:14:03 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 04:00:18 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**copy_map(t_map *map);
static void	flood_fill(char **map, int i, int j, char c);
static size_t compare_len(char *str1, char *str2, char c);

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
			if (cpy[i][j] == '0' || ft_strchr("NEWS",cpy[i][j]))
				flood_fill(cpy, i, j,cpy[i][j]);
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

static char	**copy_map(t_map *map)
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

static void	flood_fill(char **map, int i, int j,char c)
{
	if(map[i] == NULL)
		ft_error("Invalid map.");	
	if (i > 0 && compare_len(map[i - 1],map[i], c) > 0)
		ft_error("Invalid map.");
	printf("i %d\n",i);
	if(map[i + 1] != NULL && compare_len(map[i + 1],map[i], c) > 0)
		ft_error("Invalid map.");	
	if(ft_strchr("1xnews", map[i][j]))
		return;
	if (map[i][j] == ' ' || map[i][j + 1] == '\0')
		ft_error("Invalid map.");
	if(i == 0 || j == 0)
		ft_error("Invalid map.");	
	if(ft_strchr("NEWS", map[i][j]))
		map[i][j] = ft_tolower(map[i][j]);
	else
	map[i][j] = 'x';
	flood_fill(map, i - 1, j, map[i][j]);
	flood_fill(map, i, j - 1, map[i][j]);
	flood_fill(map, i + 1, j, map[i][j]);
	flood_fill(map, i, j + 1, map[i][j]);
}

static size_t compare_len(char *str1, char *str2, char c)
{
	if(!ft_strchr(str2, c))
		return(0);
	return(ft_strlen(str1) < (size_t)(ft_strrchr(str2, c) - str2) + 1);
}
