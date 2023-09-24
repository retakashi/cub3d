/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:47:14 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 14:25:57 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_vector(t_vector *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}

double	vectorlen(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}
