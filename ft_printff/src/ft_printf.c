#include "../includes/ft_printf.h"

static void	ft_printf_helper(t_combination *comb, va_list *args, size_t *count)
{
	if ((*comb).type == 'c')
		*count += handle_char(va_arg(*args, int), *comb);
	else if (comb->type == 's')
		*count += handle_str(va_arg(*args, char *), *comb);
	else if (comb->type == 'd' || comb->type == 'i')
		*count += handle_int(va_arg(*args, int), *comb);
	else if (comb->type == 'u')
		*count += handle_unsigned(va_arg(*args, unsigned int), *comb);
	else if (comb->type == 'x' || comb->type == 'X')
		*count += handle_hex(va_arg(*args, unsigned int), *comb);
	else if (comb->type == 'p')
		*count += handle_ptr(va_arg(*args, void *), *comb);
	else if (comb->type == '%')
		*count += handle_char('%', *comb);
}

int	ft_printf(const char *line, ...)
{
	va_list			args;
	size_t			count;
	t_combination	comb;

	count = 0;
	va_start(args, line);
	while (*line)
	{
		if (*line == '%')
		{
			comb = parse_format(line + 1, &args);
			line += comb.next_index;
			ft_printf_helper(&comb, &args, &count);
			line++;
		}
		else
		{
			count += ft_putchr(*line);
			line++;
		}
	}
	va_end(args);
	return (count);
}
