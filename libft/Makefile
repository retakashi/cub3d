NAME = libft.a

CC = cc
INCDIR = .
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

LIBDIR	=	.

SRCS = $(shell find $(LIBDIR) -name "*.c" -type f | xargs)

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all