include Include.mk

CFLAGS = -Wall -Wextra -Werror -I./includes
SRCS := $(addprefix srcs/, $(SRCS))
OBJS = $(SRCS:.c=.o)
HEADERS = includes/libft.h includes/ft_printf.h
NAME = libft.a

all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	ar rcs $@ $(OBJS)
clean: 
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
