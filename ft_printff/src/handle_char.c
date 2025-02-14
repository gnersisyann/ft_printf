#include "../includes/ft_printf.h"

int	handle_char(char c, t_combination comb)
{
	int	count;

	count = 0;
	if (comb.flags & '-')
	{
		count += ft_putchr(c);
		count += add_padding(comb.width - 1, ' ');
	}
	else
	{
		if (comb.flags & '0')
			count += add_padding(comb.width - 1, '0');
		else
			count += add_padding(comb.width - 1, ' ');
		count += ft_putchr(c);
	}
	return (count);
}
