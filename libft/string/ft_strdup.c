/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:16:48 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/29 02:44:12 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*c;

	c = malloc (sizeof(char) * (ft_strlen(src) + 1));
	if (!c)
		return (NULL);
	i = -1;
	while (src[++i])
		c[i] = src[i];
	c[i] = '\0';
	return (c);
}
