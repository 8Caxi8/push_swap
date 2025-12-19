/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:22:56 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 13:22:57 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"

typedef struct s_values
{
	int			a_size;
	int			total;
	int			n[2];
	int			best_cost;
	int			lis_len;
	int			*lis;
}				t_values;

typedef struct s_node
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			*moves;
	int				depth;
	struct s_node	*next;
}					t_node;

void	execute_rotations(t_list **stack_a, t_list **stack_b, t_values x);
void	rotate_to_push(t_list **stack_a, t_list **stack_b, t_values x);
void	rotate_a_reverse_b(t_list **stack_a, t_list **stack_b, t_values x);
void	reverse_a_rotate_b(t_list **stack_a, t_list **stack_b, t_values x);
void	reverse_to_push(t_list **stack_a, t_list **stack_b, t_values x);
void	start_algorithm(t_list **stack_a, t_list **stack_b);
void	push_listurk(t_list **stack_a, t_list **stack_b, t_values *x);
void	push_chunkturk(t_list **stack_a, t_list **stack_b, t_values *x);
void	order_stack(t_list **stack_a, t_values *x);
void	push_lis_to_b(t_list **stack_a, t_list **stack_b, t_values *x);
void	push_chunkturk_to_b(t_list **stack_a, t_list **stack_b, t_values *x);
void	push_bf_to_a(t_list **stack_a, t_list **stack_b, t_values *x);
int		node_is_max(t_list *node, t_list *stack);
int		node_is_min(t_list *node, t_list *stack);
t_list	*swap(t_list **lst);
void	push(t_list **lst_receive, t_list **lst_give);
t_list	*rotate(t_list **lst);
t_list	*reverse_rotate(t_list **lst);
void	max_ascending(t_list *stack_a, t_values *x);
void	get_lis(int max_len[2], int *i_lis, t_values *x);
void	calculate_lis(t_list *stack_a, int max_len[2], int *len_lis,
			int *i_lis);
void	update_lis(int i[2], int max_len[2], int *len_lis, int *i_lis);
int		get_stack(char **tab, long **n, t_list **stack_a);
void	clear(t_list *stack_a, t_list *stack_b, long **n, char **str);
void	normalize(t_list **stack_a, long **n, char **str);
int		smaller_than(t_list *node, t_list *stack);
int		is_ascending(t_list *stack_a);
void	bfs(t_list **stack_a);
void	add_queue(t_node *new, t_node **head, t_node **tail);
t_node	*dup_node(t_node *node);
char	*encode_state(t_node *node);
void	*dup_int(void *content);
void	apply_both_moves(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_both_reverse_rotate(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_both_rotate(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_both_swap(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
char	*get_last_move(char *moves);
void	apply_b_moves(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_reverse_rotate_b(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_rotate_b(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_swap_b(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_push_b(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_a_moves(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_push_a(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_reverse_rotate_a(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_rotate_a(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	apply_swap_a(t_node *node, t_node **head, t_node **tail,
			t_list **visited);
void	clear_queue(t_node **head);
void	start_queue(t_node **head, t_node **tail, t_list **stack_a);
void	next_node(t_node **head);
void	clear_node(t_node *node);
int		check_state(char *state, t_list *visited);
void	add_layer(t_node **head, t_node **tail, t_list **visited);
void	find_best_cost(t_list **stack_a, t_list **stack_b, t_values *x);
void	atualize_best_cost(int i[2], t_values *x);
int		best_friend_to_a(t_list *top, t_list *node, t_list *stack_a);
void	push_bfsturk(t_list **stack_a, t_list **stack_b, t_values *x);
void	push_to_b(t_list **stack_a, t_list **stack_b, t_values *x);
void	bfs_simpler(t_list **stack_a, t_values *x);

#endif