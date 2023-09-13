/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:23 by minabe            #+#    #+#             */
/*   Updated: 2023/09/13 17:41:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_rgb(char *rgb)
{
	char	**colors;
	int		r;
	int		g;
	int		b;
	int		i;

	colors = ft_split(rgb, ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	i = 0;
	while (i < 3)
	{
		ft_free(colors[i]);
		i++;
	}
	ft_free(colors);
	return (r << 16 | g << 8 | b);
}

void	add_textures(t_game *game, t_header *header)
{
	t_wall	wall;
	int		height;
	int		width;

	height = TEX_HEIGHT;
	width = TEX_WIDTH;
	wall = game->wall;
	game->ceiling_color = create_rgb(header->ceiling_color);
	game->floor_color = create_rgb(header->floor_color);
	wall.north_tex = mlx_xpm_file_to_image(game->ptr, header->north_tex_path, &width, &height);
	wall.south_tex = mlx_xpm_file_to_image(game->ptr, header->south_tex_path, &width, &height);
	wall.west_tex = mlx_xpm_file_to_image(game->ptr, header->west_tex_path, &width, &height);
	wall.east_tex = mlx_xpm_file_to_image(game->ptr, header->east_tex_path, &width, &height);
	if (wall.north_tex == NULL || wall.south_tex == NULL || wall.west_tex == NULL || wall.east_tex == NULL)
		ft_error("Failed to load texture");
}

void	remove_textures(t_game *game)
{
	mlx_destroy_image(game->ptr, game->wall.north_tex);
	mlx_destroy_image(game->ptr, game->wall.south_tex);
	mlx_destroy_image(game->ptr, game->wall.west_tex);
	mlx_destroy_image(game->ptr, game->wall.east_tex);
}
