NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
CFLAGS += $(INCFLAGS)


INCDIR	=	./includes
INC	=	$(addprefix -I,$(INCDIR)) 

SRCSDIR = ./srcs
SRCS	=	$(shell find $(SRCSDIR) -name "*.c" | xargs)

OBJSDIR = ./objs
OBJS	=	$(patsubst $(SRCSDIR)/%.c,$(OBJSDIR)/%.o,$(SRCS))
DEPS	=	$(OBJS:.o=.d)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) ./minilibx-linux/libmlx_Darwin.a
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) ./minilibx-linux/libmlx_Darwin.a $(LDFLAGS) -o $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

-include $(DEPS)

clean:
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all

debug: CFLAGS += -g -fsanitize=address
debug: re

.PHONY: all clean fclean re bonus norm debug
