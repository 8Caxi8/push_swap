/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:27:14 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/11 03:58:56 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

void	clear(t_list *stack_a, t_list *stack_b, long **n)
{
	ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
	free(n);
}

int	greater_than(t_list *node, t_list *stack)
{
	int		n;

	n = 0;
	while (stack)
	{
		if (*(int *)node->content < *(int *)stack->content)
			n++;
		stack = stack->next;
	}
	return (n);
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

t_list	*get_stack(char **tab, long **n)
{
	int		i;
	int		j;
	t_list	*stack_a;
		
	i = -1;
	stack_a = NULL;
	while(tab[++i])
	{
		j = 0;
		while(ft_isdigit(tab[i][j]) || tab[i][j] == '-' || tab[i][j] == '+')
		j++;
		n[i] = malloc(sizeof(long));
		*n[i] = ft_atoi(tab[i]);
		if (tab[i][j] != 0 || ft_lstfind(stack_a, n[i]) || 
			*n[i] > INT_MAX || *n[i] < INT_MIN)
		{
			write(2, "Error\n", 6);
			(free(n[i]), clear(stack_a, NULL, n), exit(1));
		}
		ft_lstadd_back(&stack_a, ft_lstnew(n[i]));
	}
	return (stack_a);
}

void	lstprint(t_list	*stack_a, t_list	*stack_b)
{
	if (!stack_a)
		return ;
	ft_printf("a:");
	while(stack_a)
	{
		ft_printf("%d - > ", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("NULL\n");
	if (!stack_b)
		return ;
	ft_printf("b:");
	while(stack_b)
	{
		ft_printf("%d - > ", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("NULL\n");
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**str;
	long	**n;

	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		i = -1;
		ac = 0;
		while (str[++i])
			ac++;
		n = malloc(ac * sizeof(long *));
		stack_a = get_stack(str, n);
		i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
		stack_b = NULL;
		if (is_ascending(stack_a) != ft_lstsize(stack_a) - 1)
			start_algorithm(&stack_a, &stack_b);
		clear(stack_a, stack_b, n);
	}
	else if (ac > 2)
	{	
		n = malloc((ac - 1) * sizeof(long *));
		stack_a = get_stack(av + 1, n);
		/* ft_printf("------STEP 1--------\n");
		lstprint(stack_a, NULL); */
		stack_b = NULL;
		if (is_ascending(stack_a) != ft_lstsize(stack_a) - 1)
			start_algorithm(&stack_a, &stack_b);
		clear(stack_a, stack_b, n);
	}
	return (0);
}//33 77 14 87 85 41 25 43 35 16 93 45 68 51 30 89 65 81 10 31 44 53 79 76 74 40 49 9 5 71 3 42 78 90 96 70 32 26 19 46 22 92 52 2 34 21 80 6 37 8 62 29 55 82 11 28 4 36 72 1 75 23 97 61 64 60 38 47 66 56 94 17 59 91 58 48 73 69 18 7 84 50 95 13 15 24 27 98 63 12 67 83 39 100 99 86 57 20 54 88