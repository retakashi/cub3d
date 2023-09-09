/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:10:10 by minabe            #+#    #+#             */
/*   Updated: 2023/09/09 15:07:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void		my_mlx_pixel_put(t_game *game, int x, int y, int color)
// {
// 	char	*dst;
// 	t_image	*img;

// 	dst = game->ptr + (y * game-> + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

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
	// int		i;
	// int		j;

	(void)game;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			my_mlx_pixel_put(game->img, i, j, game->img->color);
		}
	}
	mlx_put_image_to_window(game->ptr, game->win_ptr, game->img->img, 0, 0);
	// ray = ft_calloc(game->width, sizeof(t_ray *));
	// if (ray == NULL)
	// 	ft_error("Malloc failed.");
	// i = 0;
	// while (i < game->width)
	// {
	// 	ray[i] = ft_calloc(game->height, sizeof(t_ray));
	// 	if (ray[i] == NULL)
	// 		ft_error("Malloc failed.");
	// 	j = 0;
	// 	while (j < game->height)
	// 	{
	// 		calculate_ray(game, &ray[i][j]);
	// 		if (ray[i][j].hit == true)
	// 			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	// 		else if (ray[i][j].hit == false)
	// 			my_mlx_pixel_put(&img, i, j, 0x000000FF);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// free_2d((void **)ray);
	return (EXIT_SUCCESS);
}
