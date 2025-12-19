/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:55:01 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/18 23:25:32 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list **lst)
{
	t_list	*new_head;

	if (!lst || !*lst || !(*lst)->next)
		return (NULL);
	new_head = (*lst)->next;
	(*lst)->next = new_head->next;
	new_head->next = *lst;
	*lst = new_head;
	return (*lst);
}

void	push(t_list **lst_receive, t_list **lst_give)
{
	t_list	*tmp;

	if (!lst_give || !*lst_give)
		return ;
	tmp = *lst_give;
	*lst_give = tmp->next;
	tmp->next = (*lst_receive);
	*lst_receive = tmp;
}

t_list	*rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return (NULL);
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = tmp;
	return (*lst);
}

t_list	*reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return (NULL);
	last = (*lst);
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	return (*lst);
}
