/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:55:01 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/08 17:56:01 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*new_head;
	
	if(!lst || !*lst || !(*lst)->next)
		return ;
	new_head = (*lst)->next;
	(*lst)->next = new_head->next;
	new_head->next = *lst;
	*lst = new_head;
}

void	ft_push(t_list **lst_receive, t_list **lst_give)
{
	t_list	*tmp;
	
	if(!lst_give || !*lst_give)
		return ;
	tmp = *lst_give;
	*lst_give = tmp->next;
	tmp->next = (*lst_receive);
	*lst_receive = tmp;
}

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	
	if(!lst || !*lst || !(*lst)->next)
		return ;
		
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*first;
	
	if(!lst || !*lst || !(*lst)->next)
		return ;
		
	first = *lst;
	tmp = first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*lst = first->next;
	first->next = NULL;
}
