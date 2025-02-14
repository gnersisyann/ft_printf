#include "../includes/ft_printf.h"

int	add_precision(char *str, t_combination comb)
{
	int	count;
	int	len;
	int	has_sign;

	count = 0;
	len = ft_strlen(str);
	has_sign = (str[0] == '-');
	if (has_sign)
		len--;
	if (comb.type == 's' && comb.precision >= 0 && comb.precision < len)
		len = comb.precision;
	if (comb.type != 's' && comb.precision >= 0)
	{
		while (comb.precision-- > len)
			count += ft_putchr('0');
	}
	if (str[0] == '-')
		str++;
	count += ft_putstr(str);
	return (count);
}

int	add_prefix(int sign, t_combination comb, char *str)
{
	int	count;

	count = 0;
	if (sign)
		count += ft_putchr(sign);
	if (comb.type == 'p' || ((comb.flags & FLAG_HASH) && (comb.type == 'x'
				|| comb.type == 'X') && (str[0] != '0' && str[0] != '\0')))
	{
		if (comb.type == 'X')
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");
	}
	return (count);
}

int	get_sign(char *str, int is_signed, t_combination comb)
{
	if (!is_signed)
		return (0);
	if (str[0] == '-')
		return ('-');
	if (comb.flags & FLAG_PLUS)
		return ('+');
	if (comb.flags & FLAG_SPACE)
		return (' ');
	return (0);
}

int	add_padding(int width, char c)
{
	int	count;

	count = 0;
	while (width-- > 0)
		count += ft_putchr(c);
	return (count);
}
