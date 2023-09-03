NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(INCFLAGS)

INCDIR	=	./includes
INC	=	$(addprefix -I,$(INCDIR)) 

SRCSDIR = ./srcs
SRCS	=	$(shell find $(SRCSDIR) -name "*.c" | xargs)
OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBDIR)

clean:
		$(MAKE) fclean -C $(LIBDIR)
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

.PHONY: all clean fclean re bonus norm debug
