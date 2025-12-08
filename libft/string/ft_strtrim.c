/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:12:11 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/29 19:16:35 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_min;
	size_t	len_max;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len_min = 0;
	len_max = ft_strlen(s1);
	if (len_max > 0)
		len_max--;
	while (s1[len_min] && ft_strchr(set, s1[len_min]))
		len_min++;
	if (len_min == ft_strlen(s1))
		return (ft_strdup(""));
	while (len_max > len_min && ft_strchr(set, s1[len_max]))
		len_max--;
	str = ft_calloc((len_max - len_min) + 2, 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + len_min, (len_max - len_min) + 2);
	return (str);
}
