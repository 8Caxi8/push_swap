/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:38:33 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/28 14:12:47 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*desc;
	const unsigned char	*srcc;
	size_t				i;

	desc = dest;
	srcc = src;
	if (desc < srcc)
	{
		i = -1;
		while (++i < n)
			desc[i] = srcc[i];
	}
	else if (desc > srcc)
	{
		i = n + 1;
		while (--i > 0)
			desc[i - 1] = srcc[i - 1];
	}
	return (dest);
}
