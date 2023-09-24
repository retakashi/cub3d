/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:57:04 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 16:14:43 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_digit(int n, size_t digit);

char	*ft_itoa(int n)
{
	size_t	digit;
	char	*nbr;
	char	*p;

	digit = check_digit(n, 0);
	nbr = malloc(sizeof(char) * (digit + 1));
	if (!nbr)
		ft_error("malloc failed.");
	p = nbr + digit;
	*p = '\0';
	if (n <= 0)
	{
		*nbr = '-';
		*--p = -(n % 10) + '0';
		n /= -10;
	}
	while (n != 0)
	{
		*--p = n % 10 + '0';
		n /= 10;
	}
	return (nbr);
}

static int	check_digit(int n, size_t digit)
{
	if (n < 0)
	{
		n /= 10;
		return (check_digit(n, digit + 1));
	}
	if (n < 10)
		return (digit + 1);
	return (check_digit(n / 10, digit + 1));
}
