/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:23 by minabe            #+#    #+#             */
/*   Updated: 2023/09/16 21:47:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_textures(t_game *game, t_header *header)
{
	int		height;
	int		width;

	height = TEX_HEIGHT;
	width = TEX_WIDTH;
	game->ceiling_color = create_rgb(header->ceiling_color);
	game->floor_color = create_rgb(header->floor_color);
	printf("north_tex_path\n%s\n", header->north_tex_path);
	game->wall.north = mlx_xpm_file_to_image(game->ptr, header->north_tex_path, &width, &height);
	game->wall.south = mlx_xpm_file_to_image(game->ptr, header->south_tex_path, &width, &height);
	game->wall.west = mlx_xpm_file_to_image(game->ptr, header->west_tex_path, &width, &height);
	game->wall.east = mlx_xpm_file_to_image(game->ptr, header->east_tex_path, &width, &height);
	if (game->wall.north == NULL || game->wall.south == NULL || game->wall.west == NULL || game->wall.east == NULL)
		ft_error("Failed to load texture");
	game->wall.north->addr = mlx_get_data_addr(game->wall.north, &game->wall.north->bits_per_pixel, &game->wall.north->line_length, &game->wall.north->endian);
	game->wall.south->addr = mlx_get_data_addr(game->wall.south, &game->wall.south->bits_per_pixel, &game->wall.south->line_length, &game->wall.south->endian);
	game->wall.west->addr = mlx_get_data_addr(game->wall.west, &game->wall.west->bits_per_pixel, &game->wall.west->line_length, &game->wall.west->endian);
	game->wall.east->addr = mlx_get_data_addr(game->wall.east, &game->wall.east->bits_per_pixel, &game->wall.east->line_length, &game->wall.east->endian);
	if (game->wall.north->addr == NULL || game->wall.south->addr == NULL || game->wall.west->addr == NULL || game->wall.east->addr == NULL)
		ft_error("Failed to get texture address");
}

void	remove_textures(t_game *game)
{
	mlx_destroy_image(game->ptr, game->wall.north);
	mlx_destroy_image(game->ptr, game->wall.south);
	mlx_destroy_image(game->ptr, game->wall.west);
	mlx_destroy_image(game->ptr, game->wall.east);
}
