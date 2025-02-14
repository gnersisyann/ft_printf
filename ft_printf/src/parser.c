#include "../includes/ft_printf.h"

static void	parse_format_helper(const char **format, t_combination *comb,
		int *i)
{
	*i = 0;
	comb->flags = 0;
	comb->width = 0;
	comb->precision = -1;
	comb->type = 0;
	comb->next_index = 0;
	while ((*format)[*i] && ((*format)[*i] == '-' || (*format)[*i] == '0'
			|| (*format)[*i] == '#' || (*format)[*i] == '+'
			|| (*format)[*i] == ' '))
	{
		if ((*format)[*i] == '-')
			comb->flags |= FLAG_MINUS;
		else if ((*format)[*i] == '0')
			comb->flags |= FLAG_ZERO;
		else if ((*format)[*i] == '#')
			comb->flags |= FLAG_HASH;
		else if ((*format)[*i] == '+')
			comb->flags |= FLAG_PLUS;
		else if ((*format)[*i] == ' ')
			comb->flags |= FLAG_SPACE;
		(*i)++;
	}
}

static void	precision_helper(const char **format, t_combination *comb, int *i,
		va_list **args)
{
	if ((*format)[*i] == '.')
	{
		(*i)++;
		if ((*format)[*i] == '*')
		{
			comb->precision = va_arg(**args, int);
			(*i)++;
		}
		else
		{
			comb->precision = 0;
			while ((*format)[*i] >= '0' && (*format)[*i] <= '9')
			{
				comb->precision = comb->precision * 10 + ((*format)[*i] - '0');
				(*i)++;
			}
		}
	}
}

t_combination	parse_format(const char *format, va_list *args)
{
	t_combination	comb;
	int				i;

	parse_format_helper(&format, &comb, &i);
	if (format[i] == '*')
	{
		comb.width = va_arg(*args, int);
		i++;
	}
	else
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			comb.width = comb.width * 10 + (format[i] - '0');
			i++;
		}
	}
	precision_helper(&format, &comb, &i, &args);
	comb.type = format[i];
	comb.next_index = i + 1;
	return (comb);
}
