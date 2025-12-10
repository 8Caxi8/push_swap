/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:24:04 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/10 19:39:48 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
		if (n == ft_lstsize(*stack_a))
			exit(1);
	}
	if (n <= ft_lstsize(*stack_a) / 2)
		while (n-- > 0)
			(write(1, "ra\n", 3));
	else
		while (n++ <= ft_lstsize(*stack_a) - 1)
			(write(1, "rra\n", 4));
}

void	start_algorithm(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push_to_b(stack_a, stack_b);
	/* ft_printf("------STEP 1--------\n");
	lstprint(*stack_a, *stack_b); */
	sort_3(stack_a);
	/* ft_printf("------STEP 2--------\n");
	lstprint(*stack_a, *stack_b); */
	while (ft_lstsize(*stack_b) > 0)
		push_to_a(stack_a, stack_b);
	/* ft_printf("------STEP 3--------\n");
	lstprint(*stack_a, *stack_b); */
	if (is_ascending(*stack_a) != ft_lstsize(*stack_a) - 1)
		order_stack(stack_a);
}
/* int	best_friend_to_b(t_list *node,t_list *stack)
{
	int	diff;
	
	if(!stack)
		return (1);
	diff = ft_abs(*(int *)node->content - *(int *)stack->content);
	if (node_is_min(node, stack) && node_is_max(stack, stack))
		return (1);
	if (*(int *)node->content < *(int *)stack->content)
		return (0);
	stack = stack->next;
	while (stack)
	{
		if (diff > ft_abs(*(int *)node->content - *(int *)stack->content) &&
			*(int *)node->content > *(int *)stack->content)
			return (0);
		stack=stack->next;
	}
	return (1);
} */

int	best_friend_to_b(t_list *node,t_list *stack)
{
	long	diff;
	
	if(!stack)
		return (1);
	diff = *(int *)node->content - *(int *)stack->content;
	if (node_is_min(node, stack) && node_is_max(stack, stack))
		return (1);
	if (*(int *)node->content - *(int *)stack->content < 0)
		return (0);
	stack = stack->next;
	while (stack)
	{
		if (diff > (*(int *)node->content - *(int *)stack->content) &&
			*(int *)node->content - *(int *)stack->content > 0)
			return (0);
		stack=stack->next;
	}
	return (1);
}

int	best_friend_to_a(t_list *node,t_list *stack)
{
	if(!stack)
		return (1);
	intmax_t diff = (intmax_t)(*(int *)node->content) - (intmax_t)(*(int *)stack->content);
	printf("Node = %d, stack = %d, diff = %zu\n", *(int *)node->content, *(int *)stack->content, diff);
	if (node_is_max(node, stack) && node_is_min(stack, stack))
		return (1);
	if (*(int *)node->content - *(int *)stack->content > 0)
		return (0);
	stack = stack->next;
	while (stack)
	{
		if (diff > (*(int *)node->content - *(int *)stack->content) &&
			*(int *)node->content - *(int *)stack->content > 0)
			{
				//ft_printf("Node = %d, stack = %d, diff = %d\n", *(int *)node->content, *(int *)stack->content, diff);
			return (0);
			}
		stack=stack->next;
	}
	return (1);
}