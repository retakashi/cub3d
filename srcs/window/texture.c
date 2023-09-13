/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:23 by minabe            #+#    #+#             */
/*   Updated: 2023/09/13 16:40:39 by minabe           ###   ########.fr       */
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
