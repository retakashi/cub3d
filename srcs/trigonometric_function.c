/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometric_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:56:47 by minabe            #+#    #+#             */
/*   Updated: 2023/09/12 15:20:34 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calculate_radian(int degree)
{
	return (degree * M_PI / 180);
}

double	rotate_vec_x(t_vector vec, double radian)
{
	return (vec.x * cos(radian) - vec.y * sin(radian));
}

double	rotate_vec_y(t_vector vec, double radian)
{
	return (vec.x * sin(radian) + vec.y * cos(radian));
}
