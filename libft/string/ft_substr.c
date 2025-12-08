/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:51:06 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/29 18:03:48 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	len_max;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		subs = malloc(1);
		if (!subs)
			return (NULL);
		*subs = 0;
		return (subs);
	}
	len_max = ft_strlen(s + start);
	if (len_max > len)
		len_max = len;
	subs = malloc(len_max + 1);
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len_max + 1);
	return (subs);
}
