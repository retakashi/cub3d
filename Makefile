NAME = cub3D
BONUS_NAME = cub3D_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
CFLAGS += $(INCFLAGS)


INCDIR	=	./includes
INC	=	$(addprefix -I,$(INCDIR)) 

SRCSDIR = ./srcs
SRCS	=	$(shell find $(SRCSDIR) -name "*.c" | xargs)

BONUSDIR = ./bonus
BONUS	=	$(shell find $(BONUSDIR) -name "*.c" | xargs)

OBJSDIR = ./objs
OBJS	=	$(patsubst $(SRCSDIR)/%.c,$(OBJSDIR)/%.o,$(SRCS))
DEPS	=	$(OBJS:.o=.d)

B_OBJDIR = ./objs_bonus
B_OBJS	=	$(patsubst $(BONUSDIR)/%.c,$(B_OBJDIR)/%.o,$(BONUS))
B_DEPS	=	$(B_OBJS:.o=.d)

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

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) $(LDFLAGS) -o $(BONUS_NAME)

$(B_OBJDIR)/%.o: $(BONUSDIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(INC) -c -o $@ $<

-include $(B_DEPS)

clean:
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all


debug: CFLAGS += -g -fsanitize=address
debug: re

.PHONY: all clean fclean re bonus norm debug