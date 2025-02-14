NAME	=	libftprintf.a

SRCS	= 	src/ft_printf.c \
			src/flags.c \
			src/flags_utils.c \
			src/handle_char.c \
			src/handle_hex.c \
			src/handle_int.c \
			src/handle_ptr.c \
			src/handle_str.c \
			src/handle_unsigned.c \
			src/handle_flags.c \
			src/parser.c \
			utils/ft_itoa_base.c \
			utils/ft_itoa_base_ptr.c \
			utils/ft_itoa_unsigned.c \
			utils/ft_itoa.c \
			utils/ft_putchr.c \
			utils/ft_putnbr.c \
			utils/ft_putstr.c \
			utils/ft_strdup.c \
			utils/ft_strlen.c \
			utils/ft_strcmp.c

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

CC = cc

all : $(NAME)

bonus : $(NAME)

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
