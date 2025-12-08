/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:37:26 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/08 17:24:45 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

void	ft_swap(t_list **lst);
void	ft_push(t_list **lst_receive, t_list **lst_give);

#endif