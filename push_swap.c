/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:27:14 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/09 14:02:16 by dansimoe         ###   ########.fr       */
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
	return(stack_a);
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
		ft_printf("-----STEP 0--------\n");
		lstprint(stack_a, stack_b);
		if (is_ascending(stack_a) != ft_lstsize(stack_a) - 1)
			start_algorithm(&stack_a, &stack_b);
		ft_printf("------STEP FINAL--------\n");
		lstprint(stack_a, stack_b);
		clear(stack_a, stack_b, n);
		//ARG="51 1 50 0 -7"; ./push_swap $ARG  
	}
	else if (ac > 2)
	{	
		n = malloc((ac - 1) * sizeof(long *));
		stack_a = get_stack(av + 1, n);
		stack_b = NULL;
		ft_printf("\n------STEP 0--------\n");
		lstprint(stack_a, stack_b);
		if (is_ascending(stack_a) != ft_lstsize(stack_a) - 1)
			start_algorithm(&stack_a, &stack_b);
		ft_printf("\n------STEP FINAL--------\n");
		lstprint(stack_a, stack_b);
		clear(stack_a, stack_b, n);
	}
	return (0);
}