NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c \
	hook_events.c \
	hook_utils.c \
	utils.c \
	validations.c \

OBJS = ${SRCS:.c=.o}
LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -Ilibft -lft -Lmlx -lmlx -lX11 -lXext -lm -Ofast -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
