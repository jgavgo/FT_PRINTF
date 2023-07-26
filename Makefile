NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_words_aux.c ft_nums_aux.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

INCLUDE = -I ./

RM = rm -f

all: $(NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) ft_printf.h
	ar -rcs $(NAME) $(OBJS)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)
 
 re: fcean all
.PHONY: all clean fclean re