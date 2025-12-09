/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:24:04 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/09 01:31:14 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
		return ((void) write(1, "sa\nrra\n", 7));
	swap(stack_a);
	if (is_ascending(reverse_rotate(stack_a)) == ft_lstsize(*stack_a) - 1)
		return ((void) write(1, "ra\n", 3));
	if (is_ascending(reverse_rotate(stack_a)) == ft_lstsize(*stack_a) - 1)
		return ((void) write(1, "rra\n", 4));
}

void	start_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	n;
	int	i;
	int	diff;
	int	minimun;
	
	while (ft_lstsize(*stack_a) > 3)
	{
		while (ft_lstsize(*stack_b) < 2 && ft_lstsize(*stack_a) > 3)
			(write(1, "pb\n", 3), push(stack_b, stack_a));
	}
	ft_printf("\n------STEP 1--------\n");
	lstprint(*stack_a, *stack_b);
	sort_3(stack_a);
	ft_printf("\n------STEP 2--------\n");
	lstprint(*stack_a, *stack_b);
	while (ft_lstsize(*stack_b) > 0)
	{
		i = -1;
		n = 0;
		minimun = ft_lstsize(*stack_a);
		while (++i < ft_lstsize(*stack_a))
		{
			diff = *(int *)(*stack_a)->content - *(int *)(*stack_b)->content;
			if (diff < minimun && diff > 0)
			{
				minimun = *(int *)(*stack_a)->content - *(int *)(*stack_b)->content;
				n = i;
			}
			rotate(*stack_a);
		}
		if (n < ft_lstsize(*stack_a) / 2)
		{
			while (n-- > 0)
				(write(1, "ra\n", 3));
			(write(1, "pa\n", 3), push(stack_a, stack_b));
		}
		else if (n < ft_lstsize(*stack_a))
		{
			while (n++ < ft_lstsize(*stack_a))
				(write(1, "rra\n", 4));
			(write(1, "pa\n", 3), push(stack_a, stack_b));
		}
		else
		{
			reverse_rotate(stack_a);
			(write(1, "pa\n", 3), push(stack_a, stack_b));
			(write(1, "ra\n", 3), rotate(stack_a));
		}
		}
	}
	ft_printf("\n------STEP 3--------\n");
	lstprint(*stack_a, *stack_b);
	if (is_ascending(*stack_a) != ft_lstsize(*stack_a) - 1)
	{
		n = 0;
		while (is_ascending(rotate(stack_a)) != ft_lstsize(*stack_a) - 1)
			n++;
		if (n < ft_lstsize(*stack_a) / 2)
			while (n-- > 0)
				(write(1, "ra\n", 3));
		else
			while (n++ < ft_lstsize(*stack_a))
				(write(1, "rra\n", 4));
	}
}
