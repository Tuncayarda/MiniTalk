CC = cc
CFLAGS = #-Wall -Wextra -Werror
LIBFT = libs/libft/libft.a
PRINTF = libs/ft_printf/libftprintf.a

all: server client

server: srcs/server.c $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) srcs/server.c \
	-I./libs/libft \
	-I./libs/ft_printf \
	\
	libs/libft/libft.a \
	libs/ft_printf/libftprintf.a \
	\
	-o server

client: srcs/client.c $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) srcs/client.c \
	-I./libs/libft \
	-I./libs/ft_printf \
	\
	libs/libft/libft.a \
	libs/ft_printf/libftprintf.a \
	\
	-o client

$(LIBFT):
	@make -sC libs/libft

$(PRINTF):
	@make -sC libs/ft_printf

clean:
	@make fclean -sC libs/libft
	@make fclean -sC libs/ft_printf

fclean: clean
	rm -rf $(NAME) server client

re: fclean all