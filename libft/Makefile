# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: randrina <randrina@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:34:53 by randrina          #+#    #+#              #
#    Updated: 2024/07/31 23:19:32 by randrina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a
RM  = rm -f
CC = cc
SRCS =		ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c \
			ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c \
			ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
			ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c	ft_memchr.c \
			ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
			ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
			ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
			get_next_line.c get_next_line_utils.c

SRC_BONUS = ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstmap_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJS    = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@	

re		: fclean $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS) $(OBJ_BONUS)

bonus : $(OBJS) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJ_BONUS)

.PHONY: all clean fclean re bonus 
