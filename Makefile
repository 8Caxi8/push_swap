NAME = push_swap

SRCS =	push_swap.c push_swap_helper.c operations.c
		
BONUS =	

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS:.c=.o)

INC_DIR = includes

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a 
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $@

libft.a:
	$(MAKE) -C libft libft.a

bonus: all

.bonus: $(NAME)
	@touch .bonus
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) *.o
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
