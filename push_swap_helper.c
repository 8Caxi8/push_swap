/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:23:10 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 17:02:37 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_list **stack_a, t_values *x)
{
	int	n;
	int	tofind;

	tofind = 0;
	n = ft_lstfind(*stack_a, &tofind) - 1;
	if (n <= x->a_size / 2)
		while (n-- > 0)
			(write(1, "ra\n", 3));
	else
		while (n++ <= x->a_size - 1)
			(write(1, "rra\n", 4));
}

int	node_is_max(t_list *node, t_list *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if ((*(int *)(node->content)) < (*(int *)(stack->content)))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	node_is_min(t_list *node, t_list *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if ((*(int *)(node->content)) > (*(int *)(stack->content)))
			return (0);
		stack = stack->next;
	}
	return (1);
}
