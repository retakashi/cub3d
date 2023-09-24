/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:59:36 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 16:52:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_game *game, t_ray *ray);
static void	init_step_and_side_distance(t_game *game, t_ray *ray);
static void	degital_differential_analyzer(t_game *game, t_ray *ray);
static void	calculate_perpendicular_wall_distance(t_game *game, t_ray *ray);

void	calculate_ray(t_game *game, t_ray *ray)
{
	init_ray(game, ray);
	init_step_and_side_distance(game, ray);
	degital_differential_analyzer(game, ray);
	calculate_perpendicular_wall_distance(game, ray);
}

static void	init_ray(t_game *game, t_ray *ray)
{
	double	camera_x;

	camera_x = 2 * ray->x / (double)WIN_WIDTH - 1;
	ray->map.x = floor(game->player.pos.x);
	ray->map.y = floor(game->player.pos.y);
	ray->dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * camera_x;
	if (ray->dir.x == 0)
		ray->delta_distance.x = DBL_MAX;
	else
		ray->delta_distance.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_distance.y = DBL_MAX;
	else
		ray->delta_distance.y = fabs(1 / ray->dir.y);
	ray->hit = false;
	ray->perpendicular_wall_distance = 0;
	ray->tex = NULL;
}

static void	init_step_and_side_distance(t_game *game, t_ray *ray)
{
	t_vector	pos;

	pos = game->player.pos;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_distance.x = (pos.x - ray->map.x) * ray->delta_distance.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_distance.x = (ray->map.x + 1.0 - pos.x) * ray->delta_distance.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = 1;
		ray->side_distance.y = (ray->map.y + 1.0 - pos.y) * ray->delta_distance.y;
	}
	else
	{
		ray->step.y = -1;
		ray->side_distance.y = (pos.y - ray->map.y) * ray->delta_distance.y;
	}
}

static void	degital_differential_analyzer(t_game *game, t_ray *ray)
{
	while (ray->hit == false)
	{
		if (ray->side_distance.x < ray->side_distance.y)
		{
			ray->side_distance.x += ray->delta_distance.x;
			ray->map.x += ray->step.x;
			ray->side = X_AXIS;
		}
		else
		{
			ray->side_distance.y += ray->delta_distance.y;
			ray->map.y += ray->step.y;
			ray->side = Y_AXIS;
		}
		if (game->map->map[(int)ray->map.y][(int)ray->map.x] == '1')
			ray->hit = true;
	}
}

static void	calculate_perpendicular_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == X_AXIS)
	{
		ray->perpendicular_wall_distance = ray->side_distance.x - ray->delta_distance.x;
		if (ray->step.x < 0)
			ray->tex = game->wall.west;
		else
			ray->tex = game->wall.east;
	}
	else
	{
		ray->perpendicular_wall_distance = ray->side_distance.y - ray->delta_distance.y;
		if (ray->step.y < 0)
			ray->tex = game->wall.north;
		else
			ray->tex = game->wall.south;
	}
}
