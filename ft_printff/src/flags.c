#include "../includes/ft_printf.h"

static void	zero_helper(char **str, int *count, t_combination *comb, int *len)
{
	int	has_prefix;

	has_prefix = comb->type == 'p' || ((comb->flags & FLAG_HASH)
			&& (comb->type == 'x' || comb->type == 'X'));
	if (has_prefix && **str != '0')
		*count += add_padding(comb->width - *len - 2, '0');
	else
		*count += add_padding(comb->width - *len, '0');
	*count += add_precision(*str, *comb);
}

int	handle_zero_flag(char *str, t_combination comb, int sign)
{
	int	count;
	int	len;
	int	is_negative;

	count = 0;
	len = ft_strlen(str);
	is_negative = (str[0] == '-');
	if (comb.precision == 0 && str[0] == '0')
	{
		count += add_padding(comb.width, ' ');
		return (count);
	}
	if (sign)
		len++;
	if (is_negative)
	{
		ft_putchr('-');
		str++;
		count++;
		len--;
	}
	else if (sign || comb.type == 'x' || comb.type == 'X')
		count += add_prefix(sign, comb, str);
	zero_helper(&str, &count, &comb, &len);
	return (count);
}

int	handle_left_align(char *str, t_combination comb, int len, int sign)
{
	int	count;
	int	has_prefix;

	count = 0;
	has_prefix = comb.type == 'p' || ((comb.flags & FLAG_HASH)
			&& (comb.type == 'x' || comb.type == 'X'));
	if (comb.precision == 0 && str[0] == '0')
	{
		count += add_padding(comb.width, ' ');
		return (count);
	}
	count += add_prefix(sign, comb, str);
	count += add_precision(str, comb);
	if (has_prefix && !(comb.type == 'x' || comb.type == 'X'))
		count += add_padding(comb.width - len - 2, ' ');
	else
		count += add_padding(comb.width - len, ' ');
	return (count);
}

static void	right_helper(t_combination *comb, char **str, int *count, int *len)
{
	int	has_prefix;

	has_prefix = comb->type == 'p' || ((comb->flags & FLAG_HASH)
			&& (comb->type == 'x' || comb->type == 'X'));
	if (comb->flags & FLAG_ZERO && comb->precision < 0)
	{
		if (has_prefix && !(comb->type == 'x' || comb->type == 'X')
			&& *str[0] != '0')
			*count += add_padding(comb->width - *len - 2, '0');
		else
			*count += add_padding(comb->width - *len, '0');
	}
	else
	{
		if (has_prefix && !(comb->type == 'x' || comb->type == 'X'))
			*count += add_padding(comb->width - *len - 2, ' ');
		else
			*count += add_padding(comb->width - *len, ' ');
	}
}

int	handle_right_align(char *str, t_combination comb, int len, int sign)
{
	int	count;
	int	has_prefix;

	count = 0;
	has_prefix = comb.type == 'p' || ((comb.flags & FLAG_HASH)
			&& (comb.type == 'x' || comb.type == 'X'));
	if (comb.precision == 0 && str[0] == '0')
	{
		count += add_padding(comb.width, ' ');
		return (count);
	}
	right_helper(&comb, &str, &count, &len);
	count += add_prefix(sign, comb, str);
	count += add_precision(str, comb);
	return (count);
}
