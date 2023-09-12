/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:10:10 by minabe            #+#    #+#             */
/*   Updated: 2023/09/12 16:46:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	// line_lengthは実際のウィンドウの横幅と違うので計算する必要がある
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

uint32_t	get_color_from_img(t_image img, int x, int y)
{
	return *(uint32_t*)(img.addr +
		(y * img.line_length + x * (img.bits_per_pixel / 8)));
}

void	print_ceiling_and_floor(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				my_mlx_pixel_put(game->img, j, i, game->ceiling_color);
			else
				my_mlx_pixel_put(game->img, j, i, game->floor_color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_game *game, int start, int end, int x)
{
	int	j;

	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	j = start;
	while (j < end)
	{
		my_mlx_pixel_put(game->img, x, j, 0x00FF0000);
		j++;
	}
}

void	draw_wall(t_game *game, t_ray *ray)
{
	int		i;
	int		win_height;

	i = 0;
	while (i < WIDTH)
	{
		ray[i].x = i;
		calculate_ray(game, &ray[i]);
		if (i == WIDTH / 2)
			printf("step: %d, %d\n", ray[i].map.x, ray[i].map.y);
			// printf("dir_len: %f\n", ray->perpendicular_wall_distance);
		// win_height = (int)(WIDTH / 2 * vectorlen(game->player.plane));
		win_height = HEIGHT;
		game->wall_height = (int)((WIDTH / 2 * vectorlen(game->player.plane)) / ray[i].perpendicular_wall_distance);
		draw_line(game, -game->wall_height / 2 + win_height / 2, game->wall_height / 2 + win_height / 2, i);
		i++;
	}
}

int	draw_window(t_game *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray) * WIDTH);
	if (ray == NULL)
		ft_error("Malloc failed");
	print_ceiling_and_floor(game);
	draw_wall(game, ray);
	mlx_put_image_to_window(game->ptr, game->win_ptr, game->img->img, 0, 0);
	ft_free(ray);
	return (EXIT_SUCCESS);
}
