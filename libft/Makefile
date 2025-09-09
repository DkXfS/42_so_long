# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apanthap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 15:53:32 by apanthap          #+#    #+#              #
#    Updated: 2021/01/15 11:20:51 by apanthap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BNS = ft_lstdelone.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_front.c\
	  ft_lstadd_back.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c\
	  ft_lstnew.c

BNS_OBJ = $(BNS:.c=.o)

FLAGS = -Wall -Wextra -Werror

SRCS = $(filter-out $(BNS), $(wildcard *.c))

OBJ = $(SRCS:.c=.o)

%.o : %.c
	gcc $(FLAGS) -c $<

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ) $(BNS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(BNS_OBJ) $(OBJ)
	ar rcs $(NAME) $(BNS_OBJ) $(OBJ)
