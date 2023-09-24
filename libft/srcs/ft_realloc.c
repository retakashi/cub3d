/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:09:31 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 16:14:55 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p, size_t size)
{
	void	*new_data;

	new_data = NULL;
	if (size == 0)
		return (NULL);
	new_data = malloc(size);
	if (new_data == NULL)
		ft_error("malloc failed.");
	if (p != NULL)
	{
		ft_memcpy(new_data, p, size);
		free(p);
	}
	return (new_data);
}
