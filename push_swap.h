/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:37:26 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/08 23:56:52 by dansimoe         ###   ########.fr       */
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

#endif