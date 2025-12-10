# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 13:17:50 by dansimoe          #+#    #+#              #
#    Updated: 2025/12/10 16:42:30 by dansimoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#CHAR functions#
SRCS_CHAR = char/ft_isalnum.c char/ft_isalpha.c char/ft_isdigit.c char/ft_isascii.c \
			char/ft_isprint.c char/ft_toupper.c char/ft_tolower.c char/ft_putchar.c

#CHAR functions#
SRCS_FD = fd/ft_putchar_fd.c fd/ft_putstr_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c

#CHAR functions#
SRCS_LIST = list/ft_lstadd_back.c list/ft_lstadd_front.c list/ft_lstclear.c \
			list/ft_lstdelone.c list/ft_lstiter.c list/ft_lstlast.c list/ft_lstmap.c \
			list/ft_lstnew.c list/ft_lstsize.c list/ft_lstfind.c

#CHAR functions#
SRCS_MEM = mem/ft_memset.c mem/ft_bzero.c mem/ft_memcpy.c mem/ft_memmove.c \
			mem/ft_memchr.c mem/ft_memcmp.c mem/ft_calloc.c

#CHAR functions#
SRCS_NUMBER = number/ft_atoi.c number/ft_itoa.c number/ft_check_base.c \
			number/ft_putnbr_base.c number/ft_imax.c number/ft_imin.c \
			number/ft_abs.c

#CHAR functions#
SRCS_STRING = string/ft_strlcpy.c string/ft_strlcat.c string/ft_strchr.c \
			string/ft_strrchr.c string/ft_strncmp.c string/ft_strnstr.c \
			string/ft_strdup.c string/ft_substr.c string/ft_strjoin.c \
			string/ft_strtrim.c string/ft_split.c string/ft_strmapi.c \
			string/ft_striteri.c string/ft_strlen.c

#GNL functions#
SRCS_GNL = gnl/get_next_line_utils.c gnl/get_next_line.c

#Printf functions#
SRCS_PRINTF = printf/ft_printf.c printf/ft_printf_csp.c \
			printf/ft_printf_idu.c printf/ft_printf_helper.c \
			printf/ft_printf_xX.c printf/ft_printf_helper2.c

#All srcs and objects#
SRCS = $(SRCS_CHAR) $(SRCS_FD) $(SRCS_LIST) $(SRCS_MEM) $(SRCS_NUMBER) $(SRCS_STRING) $(SRCS_GNL) $(SRCS_PRINTF)
OBJS = $(SRCS:.c=.o)

#Other command variables#
INC = includes
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#Rules#
%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re