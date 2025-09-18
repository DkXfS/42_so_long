NAME=so_long

CFLAGS=-Wall -Wextra -Werror -O3
LFLAGS=-lmlx -L . -L ft_printf -lftprintf -L libft -lft

SRCS=so_long.c \
	mapLoader.c \
	animation.c \
	controls.c \
	movement.c \
	game_data.c \
	navigation.c \

OBJS=$(SRCS:.c=.o)

%.o :	%.c
		cc -c -g $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C minilibx_mms_20200219
	make -C ft_printf
	make -C libft
	mv minilibx_mms_20200219/libmlx.dylib .
	cc -g $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.dylib
	make clean -C minilibx_mms_20200219
	make clean -C ft_printf
	make clean -C libft

re: fclean all

.PHONY: all clean fclean re
