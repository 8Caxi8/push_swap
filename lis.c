/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:54:00 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/18 21:48:16 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_ascending(t_list *stack_a, t_values *x)
{
	int	max_len[2];
	int	*len_lis;
	int	*i_lis;
	int	i;

	x->lis = ft_calloc(x->a_size, sizeof(int));
	if (!x->lis)
		return ;
	len_lis = malloc(x->a_size * sizeof(int));
	if (!len_lis)
		return (free(x->lis));
	i_lis = malloc(x->a_size * sizeof(int));
	if (!i_lis)
		return (free(len_lis), free(x->lis));
	i = -1;
	while (++i < x->a_size)
		len_lis[i] = 1;
	calculate_lis(stack_a, max_len, len_lis, i_lis);
	get_lis(max_len, i_lis, x);
	(free(len_lis), free(i_lis));
}

void	get_lis(int max_len[2], int *i_lis, t_values *x)
{
	int	i;

	i = -1;
	x->lis_len = max_len[0] - 1;
	while (++i < x->lis_len + 1)
	{
		x->lis[max_len[1]] = 1;
		max_len[1] = i_lis[max_len[1]];
	}
}

void	calculate_lis(t_list *stack_a, int max_len[2], int *len_lis, int *i_lis)
{
	t_list	*i_stack;
	t_list	*j_stack;
	int		i[2];

	i[0] = 1;
	max_len[0] = 1;
	i_stack = stack_a->next;
	while (i_stack)
	{
		j_stack = stack_a;
		i[1] = 0;
		while (i[1] != i[0])
		{
			if ((*(int *)i_stack->content > *(int *)j_stack->content)
				&& (len_lis[i[1]] + 1 > len_lis[i[0]]))
				update_lis(i, max_len, len_lis, i_lis);
			j_stack = j_stack->next;
			i[1]++;
		}
		i_stack = i_stack->next;
		i[0]++;
	}
}

void	update_lis(int i[2], int max_len[2], int *len_lis, int *i_lis)
{
	len_lis[i[0]] = len_lis[i[1]] + 1;
	i_lis[i[0]] = i[1];
	if (len_lis[i[0]] > max_len[0])
	{
		max_len[0] = len_lis[i[0]];
		max_len[1] = i[0];
	}
}
