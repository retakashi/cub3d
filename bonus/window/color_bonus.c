/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:28:08 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 20:02:29 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static	bool	check_valid_colors(char **colors, int *r, int *g, int *b);
static	bool	check_valid_number(int num);

int	create_rgb(char *rgb)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	colors = ft_split(rgb, ',');
	if (colors == NULL)
		ft_error("Ft_split failed.");
	if (check_valid_colors(colors, &r, &g, &b) == false)
	{
		free_2d(colors);
		ft_error("Invalid colors.");
	}
	free_2d(colors);
	return (r << 16 | g << 8 | b);
}

static	bool	check_valid_colors(char **colors, int *r, int *g, int *b)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (colors[i] == NULL)
			return (false);
		i++;
	}
	*r = ft_atoi(colors[0]);
	*g = ft_atoi(colors[1]);
	*b = ft_atoi(colors[2]);
	if (check_valid_number(*r) == false || check_valid_number(*g) == false \
		|| check_valid_number(*b) == false)
		return (false);
	return (true);
}

static	bool	check_valid_number(int num)
{
	if (num < 0 || num > 255)
		return (false);
	return (true);
}

u_int32_t	get_color_from_img(t_image *img, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}
