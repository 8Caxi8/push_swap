#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 23:35:32 by dansimoe          #+#    #+#              #
#    Updated: 2025/12/19 12:43:39 by dansimoe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

BONUS = checker

SRCS =	push_swap.c operations.c push_functions.c rotations.c best_cost.c \
		initialize.c lis.c bfs.c bfs_moves_both.c bfs_moves_a.c bfs_moves_b.c \
		bfs_helper.c bfs_helper2.c push_swap_helper.c
		
BONUS_SRCS = checker_bonus.c operations.c initialize.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS_SRCS:.c=.o)

INC_DIR = includes

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a 
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $@

libft/libft.a:
	$(MAKE) -C libft libft.a

$(BONUS): $(OBJS_BONUS) libft/libft.a 
	$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $@

bonus: .bonus

.bonus: $(BONUS)
	@touch .bonus

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) .bonus
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
