/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:19:45 by minabe            #+#    #+#             */
/*   Updated: 2023/09/24 13:59:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	slen;
	char	*str;

	slen = ft_strlen(s);
	if (slen <= start)
		str = ft_strdup("");
	else
	{
		str = malloc(sizeof(char) * (slen - start + 1));
		if (!str)
			ft_error("malloc failed");
		ft_strlcpy(str, s + start, len + 1);
	}
	return (str);
}
