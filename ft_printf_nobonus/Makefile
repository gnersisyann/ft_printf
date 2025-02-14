NAME	=	libftprintf.a

SRCS	= 	src/ft_printf.c \
			utils/ft_itoa_base.c \
			utils/ft_itoa_base_ptr.c \
			utils/ft_putchr.c \
			utils/ft_putnbr.c \
			utils/ft_putstr.c \
			utils/ft_strdup.c \
			utils/ft_strlen.c

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

CC = cc

all : $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
