/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_moves_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:40:31 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/18 21:14:24 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_a_moves(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	char	*last_move;

	last_move = get_last_move(node->moves);
	if (ft_lstsize(node->stack_a) > 1
		&& (!last_move || ft_strncmp(last_move, "sa", 2)))
		apply_swap_a(node, head, tail, visited);
	if (ft_lstsize(node->stack_a) > 2)
	{
		if (!last_move || ft_strncmp(last_move, "ra", 2))
			apply_reverse_rotate_a(node, head, tail, visited);
		if (!last_move || ft_strncmp(last_move, "rra", 3))
			apply_rotate_a(node, head, tail, visited);
	}
	apply_push_b(node, head, tail, visited);
}

void	apply_push_a(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	push(&new->stack_a, &new->stack_b);
	new_moves = ft_strjoin(new->moves, "pa\n");
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

void	apply_reverse_rotate_a(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	reverse_rotate(&new->stack_a);
	new_moves = ft_strjoin(new->moves, "rra\n");
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

void	apply_rotate_a(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*new_moves;
	char	*state;

	new = dup_node(node);
	rotate(&new->stack_a);
	new_moves = ft_strjoin(new->moves, "ra\n");
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

void	apply_swap_a(t_node *node, t_node **head, t_node **tail,
		t_list **visited)
{
	t_node	*new;
	char	*state;
	char	*new_moves;

	new = dup_node(node);
	swap(&new->stack_a);
	new_moves = ft_strjoin(new->moves, "sa\n");
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
