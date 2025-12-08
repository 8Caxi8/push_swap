/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:12:17 by caxi              #+#    #+#             */
/*   Updated: 2025/12/01 15:18:46 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	int			b_l;
	long int	n;

	b_l = ft_check_base(base);
	if (b_l < 2)
		return ;
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= b_l)
		ft_putnbr_base(n / b_l, base);
	write(1, &base[n % b_l], 1);
}
