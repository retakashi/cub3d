/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometric_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:13:08 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 16:27:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIGONOMETRIC_BONUS_H
# define TRIGONOMETRIC_BONUS_H

# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

double	calculate_radian(int degree);
double	rotate_vec_x(t_vector vec, double radian);
double	rotate_vec_y(t_vector vec, double radian);

#endif
