include Include.mk

CFLAGS = -Wall -Wextra -Werror -I./includes
SRCS := $(addprefix srcs/, $(SRCS))
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)
clean: 
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
