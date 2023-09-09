/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:10:10 by minabe            #+#    #+#             */
/*   Updated: 2023/09/09 15:40:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	// line_lengthは実際のウィンドウの横幅と違うので計算する必要がある
	dst = img->addr + (y * img->line_length +x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

uint32_t	get_color_from_img(t_image img, int x, int y)
{
	return *(uint32_t*)(img.addr +
		(y * img.line_length + x * (img.bits_per_pixel / 8)));
}

int	draw_window(t_game *game)
{
	// t_ray	**ray;
	int		i;
	int		j;

	// ray = ft_calloc(WIDTH, sizeof(t_ray *));
	// if (ray == NULL)
	// 	ft_error("Malloc failed.");
	i = 0;
	while (i < HEIGHT)
	{
		// ray[i] = ft_calloc(HEIGHT, sizeof(t_ray));
		// if (ray[i] == NULL)
		// 	ft_error("Malloc failed.");
		j = 0;
		while (j < WIDTH)
		{
			// calculate_ray(game, &ray[i][j]);
			// if (ray[i][j].hit == true)
			// 	my_mlx_pixel_put(game->img, i, j, 0x00FF0000);
			// else if (ray[i][j].hit == false)
			// 	my_mlx_pixel_put(game->img, i, j, 0x000000FF);
			if (i < HEIGHT / 2)
				my_mlx_pixel_put(game->img, j, i, game->ceiling_color);
			else
				my_mlx_pixel_put(game->img, j, i, game->floor_color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->ptr, game->win_ptr, game->img->img, 0, 0);
	return (EXIT_SUCCESS);
}
