/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helper2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:20:26 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 13:20:27 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_queue(t_node **head)
{
	t_node	*tmp;
	t_node	*next;

	tmp = *head;
	while (tmp)
	{
		clear(tmp->stack_a, tmp->stack_b, NULL, NULL);
		if (tmp->moves)
			free(tmp->moves);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	start_queue(t_node **head, t_node **tail, t_list **stack_a)
{
	t_node	*first;

	first = malloc(sizeof(t_node));
	if (!first)
		(clear(*stack_a, NULL, NULL, NULL), exit(1));
	first->stack_a = ft_lstmap(*stack_a, dup_int, free);
	first->stack_b = NULL;
	first->moves = NULL;
	first->next = NULL;
	first->depth = 0;
	*head = first;
	*tail = first;
}

void	add_queue(t_node *new, t_node **head, t_node **tail)
{
	if (!*tail)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
}
