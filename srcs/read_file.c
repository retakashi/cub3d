/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:06:25 by minabe            #+#    #+#             */
/*   Updated: 2023/09/05 14:04:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_map(char **file, t_map *map);
static char	*read_and_join(char *map, int fd, char *buf);
static void	get_header(char **file, t_header *header);
static void	free_2d(char **strs);

void	get_file(char *file, t_map *map, t_header *header)
{
	int		fd;
	char	*buf;
	char	*tmp;
	char	**splited_file;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open file");
	tmp = ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		ft_error("Malloc failed");
	tmp = read_and_join(tmp, fd, buf);
	close(fd);
	splited_file = ft_split(tmp, '\n');
	ft_free(tmp);
	get_header(splited_file, header);
	get_map(splited_file, map);
	free_2d(splited_file);
	return ;
}

static void	get_header(char **file, t_header *header)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		/* +3でいいか確認する */
		if (!ft_strncmp(file[i], "EA ", 3))
			header->east_texture_path = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "WE ", 3))
			header->west_texture_path = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "NO ", 3))
			header->north_texture_path = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "SO ", 3))
			header->south_texture_path = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "C ", 2))
			header->ceiling_color = ft_strdup(file[i] + 2);
		else if (!ft_strncmp(file[i], "F ", 2))
			header->floor_color = ft_strdup(file[i] + 2);
		else
			ft_error("Invalid header");
		i++;
	}
	return ;
}

static char	*read_and_join(char *file, int fd, char *buf)
{
	char	*tmp;
	ssize_t	read_size;

	read_size = 1;
	while (read_size != 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			ft_error("Failed to read file\n");
		tmp = ft_strjoin(file, buf);
		ft_free(file);
		file = tmp;
	}
	ft_free(buf);
	return (file);
}

static void	get_map(char **file, t_map *map)
{
	int		i_file;
	int		i_map;

	map->height = count_map_height(file);
	map->map = ft_calloc(sizeof(char *), (map->height + 1));
	if (map->map == NULL)
		ft_error("Malloc failed");
	/* 初期位置が確定しているのかわからん。要検討 */
	i_file = 6;
	i_map = 0;
	while (file[i_file] != NULL)
	{
		map->map[i_map] = ft_strdup(file[i_file]);
		i_file++;
		i_map++;
	}
	return ;
}

static void	free_2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		ft_free(strs[i]);
		i++;
	}
	ft_free(strs);
	return ;
}
