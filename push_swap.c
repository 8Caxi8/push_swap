/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:27:14 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/08 17:24:16 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	clear(t_list *stack_a, t_list *stack_b, long **n)
{
	ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
	free(n);
}

t_list	*get_stack(char **av, long **n)
{
	int		i;
	int		j;
	t_list	*stack_a;
	
	i = 0;
	stack_a = NULL;
	while(av[++i])
	{
		j = 0;
		while(ft_isdigit(av[i][j]) || av[i][j] == '-' || av[i][j] == '+')
		j++;
		n[i - 1] = malloc(sizeof(long));
		*n[i - 1] = ft_atoi(av[i]);
		if (av[i][j] != 0 || ft_lstfind(stack_a, n[i - 1]) || 
			*n[i - 1] > INT_MAX || *n[i - 1] < INT_MIN)
		{
			write(2, "Error\n", 6);
			(free(n[i - 1]), clear(stack_a, NULL, n), exit(1));
		}
		ft_lstadd_back(&stack_a, ft_lstnew(n[i - 1]));
	}
	return(stack_a);
}

void	ft_lstprint(t_list	*lst)
{
	while(lst)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	long **n;
	
	if (ac > 2)
	{
		n = malloc((ac - 1) * sizeof(long *));
		stack_a = get_stack(av, n);
		stack_b = NULL;
		ft_swap(&stack_a);
		ft_lstprint(stack_a);
		clear(stack_a, stack_b, n);
	}
	return (0);
}