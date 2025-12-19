/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:20:00 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 13:20:01 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bfs(t_list **stack_a)
{
	t_node		*head;
	t_node		*tail;
	t_list		*visited;

	start_queue(&head, &tail, stack_a);
	visited = NULL;
	while (head)
	{
		if (is_ascending(head->stack_a) && !head->stack_b)
		{
			write(1, head->moves, ft_strlen(head->moves));
			clear_queue(&head);
			ft_lstclear(&visited, free);
			return ;
		}
		add_layer(&head, &tail, &visited);
		next_node(&head);
	}
}

void	bfs_simpler(t_list **stack_a, t_values *x)
{
	t_node		*head;
	t_node		*tail;
	t_list		*visited;

	start_queue(&head, &tail, stack_a);
	visited = NULL;
	while (head)
	{
		if (ft_lstsize(head->stack_a) != x->a_size)
		{
			next_node(&head);
			continue ;
		}
		if (is_ascending(head->stack_a))
		{
			write(1, head->moves, ft_strlen(head->moves));
			ft_lstclear(stack_a, free);
			*stack_a = ft_lstmap(head->stack_a, dup_int, free);
			clear_queue(&head);
			ft_lstclear(&visited, free);
			return ;
		}
		add_layer(&head, &tail, &visited);
		next_node(&head);
	}
}

t_node	*dup_node(t_node *node)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->stack_a = ft_lstmap(node->stack_a, dup_int, free);
	new->stack_b = ft_lstmap(node->stack_b, dup_int, free);
	new->moves = ft_strdup(node->moves);
	new->depth = node->depth;
	new->next = NULL;
	return (new);
}

char	*encode_state(t_node *node)
{
	char	*state;
	int		i;
	t_list	*a;
	t_list	*b;

	state = malloc(13 * sizeof(char));
	a = node->stack_a;
	b = node->stack_b;
	if (!state)
		return (NULL);
	i = -1;
	while (a)
	{
		state[++i] = *(int *)a->content + '0';
		a = a->next;
	}
	state[++i] = '|';
	while (b)
	{
		state[++i] = *(int *)b->content + '0';
		b = b->next;
	}
	state[++i] = 0;
	return (state);
}

void	*dup_int(void *content)
{
	int	*dup;

	dup = malloc(sizeof(int));
	if (!dup)
		return (NULL);
	*dup = *(int *)content;
	return (dup);
}
