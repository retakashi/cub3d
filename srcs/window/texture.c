/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:23 by minabe            #+#    #+#             */
/*   Updated: 2023/09/13 20:28:57 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	printf("north_tex_path\n%s\n", header->north_tex_path);
	wall.north = mlx_xpm_file_to_image(game->ptr, header->north_tex_path, &width, &height);
	wall.south = mlx_xpm_file_to_image(game->ptr, header->south_tex_path, &width, &height);
	wall.west = mlx_xpm_file_to_image(game->ptr, header->west_tex_path, &width, &height);
	wall.east = mlx_xpm_file_to_image(game->ptr, header->east_tex_path, &width, &height);
	if (wall.north == NULL || wall.south == NULL || wall.west == NULL || wall.east == NULL)
		ft_error("Failed to load texture");
	// wall.north->addr = mlx_get_data_addr(wall.north, &wall.north->bits_per_pixel, &wall.north->line_length, &wall.north->endian);
	// wall.south->addr = mlx_get_data_addr(wall.south, &wall.south->bits_per_pixel, &wall.south->line_length, &wall.south->endian);
	// wall.west->addr = mlx_get_data_addr(wall.west, &wall.west->bits_per_pixel, &wall.west->line_length, &wall.west->endian);
	// wall.east->addr = mlx_get_data_addr(wall.east, &wall.east->bits_per_pixel, &wall.east->line_length, &wall.east->endian);
	// if (wall.north->addr == NULL || wall.south->addr == NULL || wall.west->addr == NULL || wall.east->addr == NULL)
	// 	ft_error("Failed to get texture address");
}

void	remove_textures(t_game *game)
{
	mlx_destroy_image(game->ptr, game->wall.north);
	mlx_destroy_image(game->ptr, game->wall.south);
	mlx_destroy_image(game->ptr, game->wall.west);
	mlx_destroy_image(game->ptr, game->wall.east);
}
