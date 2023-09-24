/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:10:10 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 14:29:19 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		print_ceiling_and_floor(t_game *game);
static void		draw_wall(t_game *game, t_ray *ray);

int	draw_window(t_game *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray) * WIN_WIDTH);
	if (ray == NULL)
		ft_error("Malloc failed");
	print_ceiling_and_floor(game);
	draw_wall(game, ray);
	mlx_put_image_to_window(game->ptr, game->win_ptr, game->img->img, 0, 0);
	ft_free(ray);
	return (EXIT_SUCCESS);
}

static void	print_ceiling_and_floor(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				my_mlx_pixel_put(game->img, j, i, game->ceiling_color);
			else
				my_mlx_pixel_put(game->img, j, i, game->floor_color);
			j++;
		}
		i++;
	}
}

static void	get_wall_x(t_game *game, t_ray *ray)
{
	if (ray->side == X_AXIS)
		ray->wall_x = -game->player.pos.y + ray->perpendicular_wall_distance * ray->dir.y;
	else
		ray->wall_x = game->player.pos.x + ray->perpendicular_wall_distance * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	draw_line(t_game *game, int start, int end, int x)
{
	int			i;
	u_int32_t	color;
	double		ratio;
	double		tex_y;

	i = start;
	ratio = (double)TEX_HEIGHT / (double)game->wall_height;
	tex_y = (start - WIN_HEIGHT / 2 + game->wall_height / 2) * ratio;
	while (i < end)
	{
		color = get_color_from_img(game->ray.tex, game->ray.wall_x * TEX_WIDTH, tex_y);
		tex_y += ratio;
		my_mlx_pixel_put(game->img, x, i, color);
		i++;
	}
}

static void	draw_wall(t_game *game, t_ray *ray)
{
	int		i;
	int		win_height;
	int		draw_start;
	int		draw_end;

	i = 0;
	while (i < WIN_WIDTH)
	{
		ray[i].x = i;
		calculate_ray(game, &ray[i]);
		get_wall_x(game, &ray[i]);
		win_height = WIN_HEIGHT;
		game->wall_height = (int)(win_height / ray[i].perpendicular_wall_distance);
		draw_start = -game->wall_height / 2 + win_height / 2;
		draw_end = game->wall_height / 2 + win_height / 2;
		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;
		game->ray = ray[i];
		draw_line(game, draw_start, draw_end, i);
		i++;
	}
}
