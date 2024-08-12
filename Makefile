# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: randrina <randrina@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 19:22:56 by randrina          #+#    #+#              #
#    Updated: 2024/08/12 11:10:59 by event            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f

SRCS	= main.c map_checker.c so_long_utils.c content_check.c road_check.c \
			map_checker_utils.c struct_insert.c window_display.c \
			window_display_utils.c                       \
			move_handling.c so_long_utils1.c
OBJS	= $(SRCS:.c=.o)

NAME	= so_long

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft \
	-L./minilibx-linux -lmlx -lXext -lX11


all : $(NAME)

clean :
	$(RM) $(OBJS)
	make -C libft clean

fclean : clean
	$(RM) $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: all clean fclean re
