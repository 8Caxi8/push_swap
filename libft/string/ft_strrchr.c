/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:46:48 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/15 12:58:26 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen((char *) s) + 1;
	while (size-- > 0)
	{
		if (s[size] == (char) c)
			return ((char *)(s + size));
	}
	return (NULL);
}
