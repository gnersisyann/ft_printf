#include "../includes/ft_printf.h"

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}
