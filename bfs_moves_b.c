/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_moves_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:40:50 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/18 21:15:29 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_b_moves(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	char	*last_move;

	last_move = get_last_move(node->moves);
	if (ft_lstsize(node->stack_b) > 1
		&& (!last_move || ft_strncmp(last_move, "sb", 2)))
		apply_swap_b(node, head, tail, visited);
	if (ft_lstsize(node->stack_b) > 2)
	{
		if (!last_move || ft_strncmp(last_move, "rb", 2))
			apply_reverse_rotate_b(node, head, tail, visited);
		if (!last_move || ft_strncmp(last_move, "rrb", 3))
			apply_rotate_b(node, head, tail, visited);
	}
	apply_push_a(node, head, tail, visited);
}

void	apply_reverse_rotate_b(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	reverse_rotate(&new->stack_b);
	new_moves = ft_strjoin(new->moves, "rrb\n");
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

void	apply_rotate_b(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	rotate(&new->stack_b);
	new_moves = ft_strjoin(new->moves, "rb\n");
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

void	apply_swap_b(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	swap(&new->stack_b);
	new_moves = ft_strjoin(new->moves, "sb\n");
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

void	apply_push_b(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	push(&new->stack_b, &new->stack_a);
	new_moves = ft_strjoin(new->moves, "pb\n");
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
