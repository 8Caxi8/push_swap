/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:22:45 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 16:59:44 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			i[2];
	char		**str;
	long		**n;

	stack_b = NULL;
	stack_a = NULL;
	str = NULL;
	n = NULL;
	if (ac >= 2)
	{
		i[0] = 0;
		while (++i[0] < ac)
		{
			clear(NULL, NULL, n, str);
			str = ft_split(av[i[0]], ' ');
			i[1] = ft_tablen(str);
			n = malloc(i[1] * sizeof(long *));
			if (!get_stack(str, n, &stack_a))
				(clear(stack_a, stack_b, n, str), exit(1));
		}
		(normalize(&stack_a, n, str), start_algorithm(&stack_a, &stack_b));
	}
	return (clear(stack_a, stack_b, n, str), 0);
}

void	start_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_values	x;

	x.a_size = ft_lstsize(*stack_a);
	x.total = x.a_size;
	x.lis = 0;
	if (is_ascending(*stack_a))
		return ;
	if (x.a_size > 200)
		push_chunkturk(stack_a, stack_b, &x);
	else if (x.a_size > 10)
		push_listurk(stack_a, stack_b, &x);
	else if (x.a_size > 5)
		push_bfsturk(stack_a, stack_b, &x);
	else
		bfs(stack_a);
}

void	push_bfsturk(t_list **stack_a, t_list **stack_b, t_values *x)
{
	push_to_b(stack_a, stack_b, x);
	bfs_simpler(stack_a, x);
	push_bf_to_a(stack_a, stack_b, x);
	order_stack(stack_a, x);
}

void	push_listurk(t_list **stack_a, t_list **stack_b, t_values *x)
{
	push_lis_to_b(stack_a, stack_b, x);
	push_bf_to_a(stack_a, stack_b, x);
	order_stack(stack_a, x);
}

void	push_chunkturk(t_list **stack_a, t_list **stack_b, t_values *x)
{
	push_chunkturk_to_b(stack_a, stack_b, x);
	push_bf_to_a(stack_a, stack_b, x);
	order_stack(stack_a, x);
}
