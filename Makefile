# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:18:55 by bstablo           #+#    #+#              #
#    Updated: 2023/06/10 16:21:08 by bstablo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker_bonus

SRCS = sources/ft_atoi.c sources/checks.c sources/chain_list.c \
	sources/ft_error.c sources/list_tools.c sources/push_swap.c \
	sources/sort_three_or_five.c sources/sort_main.c sources/sorts.c sources/split.c \
	sources/find_index.c sources/rotate_and_push.c sources/rotate_type.c \
	sources/test_rotate_push_to_a.c sources/test_rotate_push_to_b.c sources/core.c

SRCS_B = sources/checker.c sources/get_next_line.c \
		sources/get_next_line_utils.c \
		sources/ft_atoi.c sources/checks.c sources/chain_list.c \
		sources/ft_error.c sources/list_tools.c \
		sources/sort_three_or_five.c sources/sort_main.c sources/sorts.c sources/split.c \
		sources/find_index.c sources/rotate_and_push.c sources/rotate_type.c \
		sources/test_rotate_push_to_a.c sources/test_rotate_push_to_b.c sources/core.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
all:	${NAME}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus: 	${NAME_B}

${NAME_B}: ${OBJS_B}
		${CC} ${CFLAGS} ${OBJS_B} -o ${NAME_B}

clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:	clean
		${RM} ${NAME} ${NAME_B}

re: fclean all

.phony: all bonus clean fclean re
