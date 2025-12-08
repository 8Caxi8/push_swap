/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:51:28 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/28 12:28:29 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*destp;

	destp = dest;
	while (n > 0)
	{
		*((unsigned char *)dest) = *((const unsigned char *)src);
		dest++;
		src++;
		n -= 1;
	}
	return (destp);
}
