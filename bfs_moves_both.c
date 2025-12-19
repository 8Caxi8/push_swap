/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_moves_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:39:05 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/18 21:16:41 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_both_moves(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	char	*last_move;

	last_move = get_last_move(node->moves);
	if (ft_lstsize(node->stack_b) > 1
		&& ft_lstsize(node->stack_a) > 1
		&& (!last_move || ft_strncmp(last_move, "ss", 2)))
		apply_both_swap(node, head, tail, visited);
	if (ft_lstsize(node->stack_b) > 2 && ft_lstsize(node->stack_a) > 2)
	{
		if (!last_move || ft_strncmp(last_move, "rr", 2))
			apply_both_reverse_rotate(node, head, tail, visited);
		if (!last_move || ft_strncmp(last_move, "rrr", 3))
			apply_both_rotate(node, head, tail, visited);
	}
}

void	apply_both_reverse_rotate(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	reverse_rotate(&new->stack_b);
	reverse_rotate(&new->stack_a);
	new_moves = ft_strjoin(new->moves, "rrr\n");
	free(new->moves);
	new->moves = new_moves;
	new->depth++;
	state = encode_state(new);
	if (!check_state(state, *visited))
	{
		ft_lstadd_back(visited, ft_lstnew(ft_strdup(state)));
		add_queue(new, head, tail);
	}
	else
		clear_node(new);
	free(state);
}

void	apply_both_rotate(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	rotate(&new->stack_b);
	rotate(&new->stack_a);
	new_moves = ft_strjoin(new->moves, "rr\n");
	free(new->moves);
	new->moves = new_moves;
	new->depth++;
	state = encode_state(new);
	if (!check_state(state, *visited))
	{
		ft_lstadd_back(visited, ft_lstnew(ft_strdup(state)));
		add_queue(new, head, tail);
	}
	else
		clear_node(new);
	free(state);
}

void	apply_both_swap(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	swap(&new->stack_b);
	swap(&new->stack_a);
	new_moves = ft_strjoin(new->moves, "ss\n");
	free(new->moves);
	new->moves = new_moves;
	new->depth++;
	state = encode_state(new);
	if (!check_state(state, *visited))
	{
		ft_lstadd_back(visited, ft_lstnew(ft_strdup(state)));
		add_queue(new, head, tail);
	}
	else
		clear_node(new);
	free(state);
}

char	*get_last_move(char *moves)
{
	char	*last_move;

	if (!moves || !*moves)
		return (NULL);
	last_move = ft_strrchr(moves, '\n');
	while (last_move > moves && *(last_move - 1) != '\n')
		last_move--;
	return (last_move);
}
