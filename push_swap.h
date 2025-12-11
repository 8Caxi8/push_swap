/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:37:26 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/11 21:54:00 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

typedef struct s_values
{
	int			a_size;
	int			total;
	int 		n[2];
	int			best_cost;
}				t_values;

t_list	*swap(t_list **lst);
void	push(t_list **lst_receive, t_list **lst_give);
t_list	*rotate(t_list **lst);
t_list	*reverse_rotate(t_list **lst);
void	lstprint(t_list *stack_a,t_list *stack_b);
void	start_algorithm(t_list **stack_a, t_list **stack_b);
int		is_ascending(t_list *stack_a);
void	push_to_b(t_list **stack_a, t_list **stack_b, t_values *x);
void	push_to_a(t_list **stack_a, t_list **stack_b, t_values *x);
void	push_efficiently(t_list **stack_a, t_list **stack_b, t_values *x);
void	order_stack(t_list **stack_a);
int		node_is_max(t_list *node,t_list *stack);
int		node_is_min(t_list *node,t_list *stack);
int		best_friend_to_b(t_list *node, t_list *top, t_list *stack_b);
int		best_friend_to_a(t_list *node,t_list *stack);
int		smaller_than(t_list *node, t_list *stack);
int		greater_than(t_list *node, t_list *stack);
void	execute_rotations(t_list **stack_a, t_list **stack_b, t_values x);
void	rotate_to_push(t_list **stack_a, t_list **stack_b, t_values x);
void 	rotate_a_reverse_b(t_list **stack_a, t_list **stack_b, t_values x);
void 	reverse_a_rotate_b(t_list **stack_a, t_list **stack_b, t_values x);
void 	reverse_to_push(t_list **stack_a, t_list **stack_b, t_values x);
void	find_best_cost(t_list **stack_a, t_list **stack_b, t_values *x);
void	atualize_best_cost(int	i[2], t_values *x);
void	sort_3(t_list **stack_a);
void	push_high(t_list **stack_a, t_list **stack_b, t_values *x);


#endif