/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:30:18 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/18 23:29:48 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotations(t_list **stack_a, t_list **stack_b, t_values x)
{
	if (x.best_cost == ft_imax(x.n[0], x.n[1]))
		rotate_to_push(stack_a, stack_b, x);
	else if (x.best_cost
		== ft_imax(x.a_size - x.n[0], (x.total - x.a_size) - x.n[1]))
		rotate_a_reverse_b(stack_a, stack_b, x);
	else if (x.best_cost == x.a_size - x.n[0] + x.n[1])
		reverse_a_rotate_b(stack_a, stack_b, x);
	else if (x.best_cost == x.n[0] + (x.total - x.a_size) - x.n[1])
		reverse_to_push(stack_a, stack_b, x);
}

void	rotate_to_push(t_list **stack_a, t_list **stack_b, t_values x)
{
	int	i;

	i = -1;
	while (++i < ft_imin(x.n[1], x.n[0]))
		(write(1, "rr\n", 3), rotate(stack_a), rotate(stack_b));
	if (x.n[0] < x.n[1] && x.n[1] != 0)
	{
		i = -1;
		while (++i < x.n[1] - x.n[0])
			(write(1, "rb\n", 3), rotate(stack_b));
	}
	if (x.n[0] > x.n[1])
	{
		i = -1;
		while (++i < x.n[0] - x.n[1])
			(write(1, "ra\n", 3), rotate(stack_a));
	}
}

void	rotate_a_reverse_b(t_list **stack_a, t_list **stack_b, t_values x)
{
	int	i;

	i = -1;
	while (++i < ft_imin((x.total - x.a_size) - x.n[1], x.a_size - x.n[0]))
		(write(1, "rrr\n", 4), reverse_rotate(stack_a),
			reverse_rotate(stack_b));
	if ((x.a_size - x.n[0]) < ((x.total - x.a_size) - x.n[1]))
	{
		i = -1;
		while (++i < (((x.total - x.a_size) - x.n[1]) - (x.a_size - x.n[0])))
			(write(1, "rrb\n", 4), reverse_rotate(stack_b));
	}
	if ((x.a_size - x.n[0]) > ((x.total - x.a_size) - x.n[1]))
	{
		i = -1;
		while (++i < ((x.a_size - x.n[0]) - ((x.total - x.a_size) - x.n[1])))
			(write(1, "rra\n", 4), reverse_rotate(stack_a));
	}
}

void	reverse_a_rotate_b(t_list **stack_a, t_list **stack_b, t_values x)
{
	int	i;

	i = -1;
	while (++i < (x.a_size - x.n[0]))
		(write(1, "rra\n", 4), reverse_rotate(stack_a));
	i = -1;
	while (++i < x.n[1])
		(write(1, "rb\n", 3), rotate(stack_b));
}

void	reverse_to_push(t_list **stack_a, t_list **stack_b, t_values x)
{
	int	i;

	i = -1;
	while (++i < ((x.total - x.a_size) - x.n[1]))
		(write(1, "rrb\n", 4), reverse_rotate(stack_b));
	i = -1;
	while (++i < x.n[0])
		(write(1, "ra\n", 3), rotate(stack_a));
}
