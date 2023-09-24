/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:28:08 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 14:26:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	create_rgb(char *rgb)
{
	char	**colors;
	int		r;
	int		g;
	int		b;
	int		i;

	colors = ft_split(rgb, ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	i = 0;
	while (i < 3)
	{
		ft_free(colors[i]);
		i++;
	}
	ft_free(colors);
	return (r << 16 | g << 8 | b);
}

u_int32_t	get_color_from_img(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
