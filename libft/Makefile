NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CFLAGS += $(addprefix -I,$(INCDIR))
INCDIR = ./include

SRCSDIR = ./srcs
SRCS = $(shell find $(SRCSDIR) -name "*.c" -type f | xargs)

OBJSDIR = ./objs
OBJS = $(patsubst $(SRCSDIR)/%.c,$(OBJSDIR)/%.o,$(SRCS))
DEPS	=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
		$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(RM) $(NAME)

re: fclean all