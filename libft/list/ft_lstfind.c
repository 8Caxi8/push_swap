/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:25:18 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/08 15:52:12 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstfind(t_list *lst, void *tofind)
{
	if (!lst || !tofind)
		return (0);
	while(lst)
	{
		if (*(int *)lst->content == *(int *)tofind)
			return (1);
		lst = lst->next;
	}
	return (0);
}
