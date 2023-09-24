/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:43 by minabe            #+#    #+#             */
/*   Updated: 2023/09/13 16:16:16 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_map_width(char *map)
{
	size_t	i;
	size_t	j;
	size_t	width;

	i = 0;
	width = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			i++;
		j = 0;
		while (map[i + j] != '\n' && map[i + j] != '\0')
			j++;
		if (width == 0)
			width = j;
		else if (width != j && j != 0)
			ft_error("Invalid width map.");
		i += j;
	}
	return (width + 1);
}

int	count_map_height(char **file)
{
	int	i;

	i = 0;
	while (file[i] != NULL)
		i++;
	return (i - HEADER_LEN);
}
