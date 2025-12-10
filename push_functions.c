/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:13:45 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/10 19:33:29 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	i[2];
	int	n[2];
	int	a_size;
	int	b_size;
	int	best_cost;

	a_size = ft_lstsize(*stack_a);
	b_size = ft_lstsize(*stack_b);
	while (a_size > 3 && b_size < 2)
	{
		if (node_is_max(*stack_a, *stack_a))
		{
			if (node_is_max(*stack_a, *stack_b))
				(write(1, "ra\n", 3), rotate(stack_a));
		}
		else
			(write(1, "pb\n", 3), push(stack_b, stack_a));
		a_size = ft_lstsize(*stack_a);
		b_size = ft_lstsize(*stack_b);
	}
	while (a_size > 3)
	{
		i[0] = -1;
		n[1] = b_size;
		n[0] = a_size;
		best_cost = INT_MAX;
		while (++i[0] < a_size)
		{
			i[1] = -1;
			while (++i[1] < b_size)
			{
				/* ft_printf(".STEP %d - %d.\n", *(int *)(*stack_a)->content, *(int *)(*stack_b)->content);
				lstprint(*stack_a, *stack_b); */ 
				//ft_printf("<%d, %d, bff:%d>\n", n[1], n[0], best_friend_to_b(*stack_a, *stack_b));
				if (best_friend_to_b(*stack_a, *stack_b))// || node_is_min(*stack_a, *stack_b) || node_is_min(*stack_a, *stack_b))
				{
					//ft_printf("<<<%d, %d --Z %d, %d>>>\n", n[0], n[1], i[0], i[1]);
					if (ft_imin(ft_imin(ft_imin(ft_imax(i[0], i[1]),i[0] + b_size - i[1]), a_size - i[0] + i[1]), ft_imax(a_size - i[0], b_size - i[1])) < best_cost)
					{
						n[1] = i[1];
						n[0] = i[0];
						best_cost = ft_imin(ft_imin(ft_imin(ft_imax(i[0], i[1]),i[0] + b_size - i[1]), a_size - i[0] + i[1]), ft_imax(a_size - i[0], b_size - i[1]));
						//ft_printf("----%d, %d, %d-------\n", n[0], n[1], best_cost);
					}
				}
				rotate(stack_b);
			}
			rotate(stack_a);
		}
		/* ft_printf("\n###################################\n");
		ft_printf("#####%d, %d, %d###########\n", n[0], n[1], best_cost);
		ft_printf("#####<%d, %d>#####\n", n[1], n[0]);	 */		
		if (best_cost == ft_imax(n[0], n[1]))
		{
			i[0] = -1;
			while (++i[0] < ft_imin(n[1], n[0]))
				(write(1, "rr\n", 3), rotate(stack_a), rotate(stack_b));
			if (n[0] < n[1] && n[1] != 0)
			{
				i[0] = -1;
				while (++i[0] < n[1] - n[0])
					(write(1, "rb\n", 3), rotate(stack_b));
			}
			if (n[0] > n[1])
			{
				i[0] = -1;
				while (++i[0] < n[0] - n[1])
					(write(1, "ra\n", 3), rotate(stack_a));
			}
		}
		else if (best_cost == ft_imax(a_size - n[0], b_size - n[1]))
		{
			i[0] = -1;
			while (++i[0] < ft_imin(b_size - n[1], a_size - n[0]))
				(write(1, "rrr\n", 4), reverse_rotate(stack_a), reverse_rotate(stack_b));
			if ((a_size - n[0]) < (b_size - n[1]))
			{
				i[0] = -1;
				while (++i[0] < ((b_size - n[1]) - (a_size - n[0])))
					(write(1, "rrb\n", 4), reverse_rotate(stack_b));
			}
			if ((a_size - n[0]) > (b_size - n[1]))
			{
				i[0] = -1;
				while (++i[0] < ((a_size - n[0]) - (b_size - n[1])))
					(write(1, "rra\n", 4), reverse_rotate(stack_a));
			}
		}
		else if (best_cost == a_size - n[0] + n[1])
		{
			i[0] = -1;
			while (++i[0] < (a_size - n[0]))
				(write(1, "rra\n", 4), reverse_rotate(stack_a));
			i[0] = -1;
			while (++i[0] < n[1])
				(write(1, "rb\n", 3), rotate(stack_b));
			//ft_printf("################################\n");
		}
		else if (best_cost == n[0] + b_size - n[1])
		{
			i[0] = -1;
			while (++i[0] < (b_size - n[1]))
				(write(1, "rrb\n", 4), reverse_rotate(stack_b));
			i[0] = -1;
			while (++i[0] < n[0])
				(write(1, "ra\n", 3), rotate(stack_a));
			//ft_printf("********************************\n");
		}
		(write(1, "pb\n", 3), push(stack_b, stack_a));
		a_size = ft_lstsize(*stack_a);
		b_size = ft_lstsize(*stack_b);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	n;
	
	n = push_efficiently(stack_a, stack_b);
	if (n <= ft_lstsize(*stack_a) / 2)
	{
		while (n-- > 0)
			(rotate(stack_a), write(1, "ra\n", 3));
	}
	else
	{
		while (n++ < ft_lstsize(*stack_a))
			(reverse_rotate(stack_a), write(1, "rra\n", 4));
	}
	(write(1, "pa\n", 3), push(stack_a, stack_b));
}

int	push_efficiently(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	a_size;
	
	i = -1;
	a_size = ft_lstsize(*stack_a);
	while (++i < a_size)
	{
		//diff = *(int *)(*stack_a)->content - *(int *)(*stack_b)->content;
		//ft_printf("###################%d\n", best_friend_to_a(*stack_b, *stack_a));
		if (best_friend_to_a(*stack_b, *stack_a))
			return (i);
		rotate(stack_a);
	}
	//ft_printf("#################");
	return (0);
}
