/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:20:36 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 13:51:19 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack(char **tab, long **n, t_list **stack_a)
{
	int		i;
	int		j;

	i = -1;
	if (!*tab)
		return (write(2, "Error\n", 6), 0);
	while (tab[++i])
	{
		j = 0;
		while (ft_isdigit(tab[i][j]) || tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		n[i] = malloc(sizeof(long));
		*n[i] = ft_atol(tab[i]);
		if (tab[i][j] != 0 || ft_lstfind(*stack_a, n[i])
			|| *n[i] > INT_MAX || *n[i] < INT_MIN || ft_strlen(tab[i]) > 10)
			return (write(2, "Error\n", 6), ft_lstadd_back(stack_a,
					ft_lstnew(n[i])), 0);
		ft_lstadd_back(stack_a, ft_lstnew(n[i]));
	}
	return (1);
}

void	clear(t_list *stack_a, t_list *stack_b, long **n, char **str)
{
	int	i;

	if (stack_a)
		ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
	if (n)
		free(n);
	if (str)
	{
		i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
	}
}

void	normalize(t_list **stack_a, long **n, char **str)
{
	int		i;
	t_list	*tmp;

	n = malloc(ft_lstsize(*stack_a) * sizeof(long *));
	if (!n)
		(clear (*stack_a, NULL, n, str), exit(1));
	tmp = *stack_a;
	i = -1;
	while (tmp)
	{
		n[++i] = malloc(sizeof(long));
		if (!n[i])
			(clear (*stack_a, NULL, n, str), exit(1));
		*n[i] = smaller_than(tmp, *stack_a);
		tmp = tmp->next;
	}
	tmp = *stack_a;
	i = -1;
	while (tmp)
	{
		free(tmp->content);
		tmp->content = n[++i];
		tmp = tmp->next;
	}
	free(n);
}

int	smaller_than(t_list *node, t_list *stack)
{
	int		n;

	n = 0;
	while (stack)
	{
		if (*(int *)node->content > *(int *)stack->content)
			n++;
		stack = stack->next;
	}
	return (n);
}

int	is_ascending(t_list *stack_a)
{
	int		n;

	if (!stack_a)
		return (0);
	n = 1;
	while (stack_a->next)
	{
		if ((*(int *)(stack_a->content)) > (*(int *)(stack_a->next->content)))
			return (0);
		n++;
		stack_a = stack_a->next;
	}
	return (n);
}
