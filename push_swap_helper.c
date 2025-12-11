/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:24:04 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/11 20:41:17 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(t_list *stack_a)
{
	int	n;

	n = 0;
	while (stack_a->next)
	{
		n += 1 * ((*(int *)(stack_a->content)) < (*(int *)(stack_a->next->content)));
		stack_a=stack_a->next;
	}
	return (n);
}

void	sort_3(t_list **stack_a)
{
	if (is_ascending(*stack_a) == ft_lstsize(*stack_a) - 1)
		return ;
	if (is_ascending(swap(stack_a)) == ft_lstsize(*stack_a) - 1)
		return ((void) write(1, "sa\n", 3));
	if (is_ascending(rotate(stack_a)) == ft_lstsize(*stack_a) - 1)
		return ((void) write(1, "sa\nra\n", 6));
	if (is_ascending(rotate(stack_a)) == ft_lstsize(*stack_a) - 1)
		return ((void) write(1, "ra\nsa\n", 6));
	if (is_ascending(swap(stack_a)) == ft_lstsize(*stack_a) - 1)
		return ((void) write(1, "ra\n", 3));
	if (is_ascending(rotate(stack_a)) == ft_lstsize(*stack_a) - 1)
		return ((void) write(1, "rra\n", 4));
}

void	order_stack(t_list **stack_a)
{
	int	n;

	n = 0;
	while (is_ascending(*stack_a) != ft_lstsize(*stack_a) - 1)
	{
		rotate(stack_a);
		n++;
	}
	if (n <= ft_lstsize(*stack_a) / 2)
		while (n-- > 0)
			(write(1, "ra\n", 3));
	else
		while (n++ <= ft_lstsize(*stack_a) - 1)
			(write(1, "rra\n", 4));
}

int best_friend_to_b(t_list *node, t_list *top, t_list *stack_b)
{
	if (!stack_b)
		return (1);
	if (node_is_min(node, stack_b) && node_is_max(top, stack_b))
		return (1);
	
	if (*(int *)node->content < *(int *)top->content)
		return (0);
	while (stack_b)
	{
		if (*(int *)stack_b->content < *(int *)node->content && 
			*(int *)stack_b->content > *(int *)top->content && 
			*(int *)top->content  != *(int *)stack_b->content )
			return (0);
		stack_b = stack_b->next;;
	}
	return (1);
}

int	best_friend_to_a(t_list *node,t_list *stack)
{
	t_list *tmp;

	if(!stack)
		return (1);
	if (node_is_max(node, stack) && node_is_min(stack, stack))
			return (1);
	if (*(int *)stack->content < *(int *)node->content)
		return (0);
	tmp = stack->next;
	while (tmp)
	{
		if (*(int *)tmp->content > *(int *)node->content && 
			*(int *)tmp->content < *(int *)stack->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
