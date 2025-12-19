/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:32:02 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 13:27:04 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_cost(t_list **stack_a, t_list **stack_b, t_values *x)
{
	int		i[2];
	t_list	*stack1;
	t_list	*stack2;

	x->best_cost = INT_MAX;
	x->n[1] = (x->total - x->a_size);
	x->n[0] = x->a_size;
	stack1 = *stack_a;
	i[0] = -1;
	while (++i[0] < x->a_size)
	{
		i[1] = -1;
		stack2 = *stack_b;
		while (++i[1] < (x->total - x->a_size))
		{
			if (best_friend_to_a(stack1, stack2, *stack_a))
				atualize_best_cost(i, x);
			if (x->best_cost < 3)
				return ;
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
}

void	atualize_best_cost(int i[2], t_values *x)
{
	int	c[4];

	c[0] = ft_imax(i[0], i[1]);
	c[1] = i[0] + (x->total - x->a_size) - i[1];
	c[2] = (x->a_size - i[0] + i[1]);
	c[3] = ft_imax(x->a_size - i[0], (x->total - x->a_size) - i[1]);
	if (ft_imin(ft_imin(c[0], c[1]), ft_imin(c[2], c[3])) < x->best_cost)
	{
		x->n[1] = i[1];
		x->n[0] = i[0];
		x->best_cost = ft_imin(ft_imin(c[0], c[1]), ft_imin(c[2], c[3]));
	}
}

int	best_friend_to_a(t_list *top, t_list *node, t_list *stack_a)
{
	if (!stack_a)
		return (1);
	if (node_is_max(node, stack_a) && node_is_min(top, stack_a))
		return (1);
	if (*(int *)top->content - *(int *)node->content == 1)
		return (1);
	if (*(int *)top->content < *(int *)node->content)
		return (0);
	while (stack_a)
	{
		if (*(int *)stack_a->content > *(int *)node->content
			&& *(int *)stack_a->content < *(int *)top->content
			&& *(int *)top->content != *(int *)stack_a->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
