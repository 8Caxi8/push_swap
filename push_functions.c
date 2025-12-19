/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:22:35 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 13:22:36 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b, t_values *x)
{
	while (x->a_size > 5)
	{
		(write(1, "pb\n", 3), push(stack_b, stack_a));
		x->a_size--;
	}
}

void	push_lis_to_b(t_list **stack_a, t_list **stack_b, t_values *x)
{
	int	i;

	max_ascending(*stack_a, x);
	if (!x->lis)
		return ;
	i = -1;
	while (++i < x->total)
	{
		if (x->lis[i] == 0)
		{
			(write(1, "pb\n", 3), push(stack_b, stack_a));
			x->a_size--;
		}
		else
			(write(1, "ra\n", 3), rotate(stack_a));
	}
	free(x->lis);
}

void	push_chunkturk_to_b(t_list **stack_a, t_list **stack_b, t_values *x)
{
	int	i;
	int	chunck;
	int	pass;

	chunck = 0;
	while (chunck < x->total)
	{
		max_ascending(*stack_a, x);
		if (!x->lis)
			return ;
		i = -1;
		chunck += x->total / 4;
		pass = x->a_size;
		while (++i < pass)
		{
			if (x->lis[i] == 0 && *(int *)(*stack_a)->content < chunck)
			{
				(write(1, "pb\n", 3), push(stack_b, stack_a));
				x->a_size--;
			}
			else
				(write(1, "ra\n", 3), rotate(stack_a));
		}
		free(x->lis);
	}
}

void	push_bf_to_a(t_list **stack_a, t_list **stack_b, t_values *x)
{
	while ((x->total - x->a_size) > 0)
	{
		find_best_cost(stack_a, stack_b, x);
		execute_rotations(stack_a, stack_b, *x);
		(write(1, "pa\n", 3), push(stack_a, stack_b));
		x->a_size++;
	}
}
