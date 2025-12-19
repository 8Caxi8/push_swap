/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:21:06 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/19 00:08:01 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_command(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		return (push(stack_a, stack_b), 1);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		return (push(stack_b, stack_a), 1);
	else if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		return (swap(stack_a), 1);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		return (swap(stack_b), 1);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		return (swap(stack_b), swap(stack_a), 1);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		return (rotate(stack_a), 1);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		return (rotate(stack_b), 1);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		return (rotate(stack_a), rotate(stack_b), 1);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		return (reverse_rotate(stack_a), 1);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		return (reverse_rotate(stack_b), 1);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		return (reverse_rotate(stack_a), reverse_rotate(stack_b), 1);
	else
		return (0);
}

void	start_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_command(stack_a, stack_b, line))
			return ((void) write(2, "Error\n", 6), free(line));
		free(line);
		line = get_next_line(0);
	}
	if (*stack_b)
		return ((void) write(1, "KO\n", 3));
	if (!is_ascending(*stack_a))
		return ((void) write(1, "KO\n", 3));
	else
		return ((void) write(1, "OK\n", 3));
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i[2];
	char	**str;
	long	**n;

	stack_b = NULL;
	stack_a = NULL;
	str = NULL;
	n = NULL;
	if (ac >= 2)
	{
		i[0] = 0;
		while (++i[0] < ac)
		{
			clear(NULL, NULL, n, str);
			str = ft_split(av[i[0]], ' ');
			i[1] = ft_tablen(str);
			n = malloc(i[1] * sizeof(long *));
			if (!get_stack(str, n, &stack_a))
				(clear(stack_a, stack_b, n, str), exit(1));
		}
		start_checker(&stack_a, &stack_b);
	}
	return (clear(stack_a, stack_b, n, str), 0);
}
