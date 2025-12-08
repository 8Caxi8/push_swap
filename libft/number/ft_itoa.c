/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:36:09 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/30 09:22:39 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_len(int n)
{
	long	nbr;
	int		i;

	nbr = n;
	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	if (nbr < 10)
		return (i);
	else
		return (i + calc_len(nbr / 10));
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		len;
	int		i;

	len = calc_len(n);
	nbr = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (n < 0)
		nbr *= -1;
	while (i < len)
	{
		str[len - 1 - i] = (nbr % 10) + '0';
		i++;
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
