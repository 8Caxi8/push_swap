/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:07:38 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/18 21:11:55 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_node(t_node **head)
{
	t_node	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	clear_node(tmp);
}

void	clear_node(t_node *node)
{
	clear(node->stack_a, node->stack_b, NULL, NULL);
	if (node->moves)
		free(node->moves);
	free(node);
}

int	check_state(char *state, t_list *visited)
{
	if (!state)
		return (0);
	while (visited)
	{
		if (!ft_strncmp(state, (char *)visited->content, ft_strlen(state) - 1))
			return (1);
		visited = visited->next;
	}
	return (0);
}

void	add_layer(t_node **head, t_node **tail, t_list **visited)
{
	t_node	*new;

	new = dup_node(*head);
	if (new->stack_a)
		apply_a_moves(new, head, tail, visited);
	if (new->stack_b)
		apply_b_moves(new, head, tail, visited);
	if (new->stack_a && new->stack_b)
		apply_both_moves(new, head, tail, visited);
	clear_node(new);
}
