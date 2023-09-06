/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:59:36 by minabe            #+#    #+#             */
/*   Updated: 2023/09/06 19:03:16 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_game *game, t_ray *ray)
{
	ray->map.x = (int)game->player.pos.x;
	ray->map.y = (int)game->player.pos.y;
	printf("[init_ray]\n%f %f\n", game->player.dir.x, game->player.dir.y);
	if (game->player.dir.x == 0)
		ray->delta_distance.x = DBL_MAX;
	else
		ray->delta_distance.x = abs(1 / (int)game->player.dir.x);
	if (game->player.dir.y == 0)
		ray->delta_distance.y = DBL_MAX;
	else
		ray->delta_distance.y = abs(1 / (int)game->player.dir.y);
	ray->hit = false;
	ray->perpendicular_wall_distance = 0;
}

void	calculate_step_and_init_side_distance(t_game *game, t_ray *ray)
{
	if (game->player.dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_distance.x = (game->player.pos.x - ray->map.x) * ray->delta_distance.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_distance.x = (ray->map.x + 1.0 - game->player.pos.x) * ray->delta_distance.x;
	}
	if (game->player.dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_distance.y = (game->player.pos.y - ray->map.y) * ray->delta_distance.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_distance.y = (ray->map.y + 1.0 - game->player.pos.y) * ray->delta_distance.y;
	}
}

void	degital_differential_analyzer(t_game *game, t_ray *ray)
{
	while (ray->hit == false)
	{
		if (ray->side_distance.x < ray->side_distance.y)
		{
			ray->side_distance.x += ray->delta_distance.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_distance.y += ray->delta_distance.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map->map[ray->map.x][ray->map.y] == '1')
			ray->hit = true;
	}
}

void	calculate_perpendicular_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpendicular_wall_distance = ray->side_distance.x - ray->delta_distance.x;
	else
		ray->perpendicular_wall_distance = ray->side_distance.y - ray->delta_distance.y;
}

void	calculate_ray(t_game *game, t_ray *ray)
{
	init_ray(game, ray);
	calculate_step_and_init_side_distance(game, ray);
	degital_differential_analyzer(game, ray);
	calculate_perpendicular_wall_distance(ray);
}
