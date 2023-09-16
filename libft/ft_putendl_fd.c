/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:18:24 by minabe            #+#    #+#             */
/*   Updated: 2023/09/16 19:29:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

ssize_t	ft_putendl_fd(int fd, char *s)
{
	ssize_t	size;

	size = ft_putstr_fd(fd, s);
	size += ft_putchar_fd(fd, '\n');
	return (size);
}
