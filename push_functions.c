/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:13:45 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/09 13:23:49 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) < 2 && ft_lstsize(*stack_a) > 3)
		(write(1, "pb\n", 3), push(stack_b, stack_a));
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	n[2];
	
	push_efficiently(stack_a, stack_b, n);
	if (n[0] == 0 && n[1] == INT_MAX)
		(order_stack(stack_a), write(1, "pa\n", 3), push(stack_a, stack_b));
	else if (n[0] <= ft_lstsize(*stack_a) / 2)
	{
		while (n[0]-- > 0)
			(rotate(stack_a), write(1, "ra\n", 3));
		(write(1, "pa\n", 3), push(stack_a, stack_b));
	}
	else if (n[0] < ft_lstsize(*stack_a))
	{
		while (n[0]++ < ft_lstsize(*stack_a))
			(reverse_rotate(stack_a), write(1, "rra\n", 4));
		(write(1, "pa\n", 3), push(stack_a, stack_b));
	}
}

void	push_efficiently(t_list **stack_a, t_list **stack_b, int n[2])
{
	int	i;
	int	diff;
	
	i = -1;
	n[0] = 0;
	n[1] = INT_MAX;
	while (++i < ft_lstsize(*stack_a))
	{
		diff = *(int *)(*stack_a)->content - *(int *)(*stack_b)->content;
		if (diff < n[1] && diff > 0)
		{
			n[1] = *(int *)(*stack_a)->content - *(int *)(*stack_b)->content;
			n[0] = i;
		}
		rotate(stack_a);
	}
}
