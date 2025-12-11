/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:13:45 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/11 21:53:49 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_values	x;
	
	push_to_b(stack_a, stack_b, &x);
	sort_3(stack_a);
	push_to_a(stack_a, stack_b, &x);
	if (greater_than(*stack_a, *stack_a) != ft_lstsize(*stack_a) - 1)
		order_stack(stack_a);
}

void	push_low(t_list **stack_a, t_list **stack_b)
{
	int	a_size;
	int	total;

	a_size = ft_lstsize(*stack_a);
	total = a_size;
	while (a_size > 3 && (total - a_size) < 2)
	{
		if (node_is_max(*stack_a, *stack_a) && node_is_max(*stack_a, *stack_b))
				(write(1, "ra\n", 3), rotate(stack_a));
		else
		{
			(write(1, "pb\n", 3), push(stack_b, stack_a));
			a_size--;
		}
	}
}

void	push_high(t_list **stack_a, t_list **stack_b, t_values *x)
{
	x->a_size = ft_lstsize(*stack_a);
	x->total = x->a_size;
	while ((x->total - x->a_size) < 2)
	{
			(write(1, "pb\n", 3), push(stack_b, stack_a));
			x->a_size--;
	}
	while (x->a_size > 3)
	{
		find_best_cost(stack_a, stack_b, x);
		execute_rotations(stack_a, stack_b, *x);
		(write(1, "pb\n", 3), push(stack_b, stack_a));
		x->a_size--;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_values *x)
{
	int	total;

	total = ft_lstsize(*stack_a);
	if (total < 10)
		push_low(stack_a, stack_b);
	else
		push_high(stack_a, stack_b, x);
}

void	push_to_a(t_list **stack_a, t_list **stack_b, t_values *x)
{
	while ((x->total - x->a_size) > 0)
	{
		push_efficiently(stack_a, stack_b, x);
		if (x->n[0] <= x->a_size / 2)
		{
			while (x->n[0]-- > 0)
				(rotate(stack_a), write(1, "ra\n", 3));
		}
		else
		{
			while (x->n[0]++ < x->a_size)
				(reverse_rotate(stack_a), write(1, "rra\n", 4));
		}
		(write(1, "pa\n", 3), push(stack_a, stack_b));
		x->a_size++;
	}
}

void	push_efficiently(t_list **stack_a, t_list **stack_b, t_values *x)
{
	int	i;
	
	i = -1;
	x->n[0] = 0;
	while (++i < x->a_size)
	{
		if (best_friend_to_a(*stack_b, *stack_a))
			x->n[0] = i;
		rotate(stack_a);
	}
}
