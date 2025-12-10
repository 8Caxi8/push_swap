/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:37:26 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/09 20:42:43 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

t_list	*swap(t_list **lst);
void	push(t_list **lst_receive, t_list **lst_give);
t_list	*rotate(t_list **lst);
t_list	*reverse_rotate(t_list **lst);
void	lstprint(t_list *stack_a,t_list *stack_b);
void	start_algorithm(t_list **stack_a, t_list **stack_b);
int		is_ascending(t_list *stack_a);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	push_efficiently(t_list **stack_a, t_list **stack_b, int n[2]);
void	order_stack(t_list **stack_a);
int		node_is_max(t_list *node,t_list *stack);
int		node_is_min(t_list *node,t_list *stack);
int		best_friend(t_list *node,t_list *stack);

#endif