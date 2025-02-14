#include "../includes/ft_printf.h"

static void	printf_helper_one(const char **line, va_list *args, size_t *count,
		char **tmp)
{
	if (**line == 'c')
		*count += ft_putchr(va_arg(*args, int));
	else if (**line == 's')
		*count += ft_putstr(va_arg(*args, const char *));
	else if (**line == 'd' || **line == 'i')
		*count += ft_putnbr(va_arg(*args, int));
	else if (**line == 'u')
		*count += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (**line == 'x')
	{
		*tmp = ft_itoa_base(va_arg(*args, unsigned int), 16);
		*count += ft_putstr(*tmp);
		free(*tmp);
	}
	else if (**line == 'X')
	{
		*tmp = ft_itoa_base(va_arg(*args, unsigned int), -16);
		*count += ft_putstr(*tmp);
		free(*tmp);
	}
}

static void	printf_helper_two(const char **line, va_list *args, size_t *count,
		char **tmp)
{
	void	*ptr;

	if (**line == 'p')
	{
		ptr = va_arg(*args, void *);
		if (!ptr)
			*count += ft_putstr("(nil)");
		else
		{
			*count += ft_putstr("0x");
			*tmp = ft_itoa_base_ptr((unsigned long)ptr, 16);
			*count += ft_putstr(*tmp);
			free(*tmp);
		}
	}
	else if (**line == '%')
		*count += ft_putchr('%');
}

int	ft_printf(const char *line, ...)
{
	va_list	args;
	char	*tmp;
	size_t	count;

	count = 0;
	va_start(args, line);
	while (*line)
	{
		if (*line == '%')
		{
			++line;
			if (*line == 'c' || *line == 's' || *line == 'd' || *line == 'u'
				|| *line == 'i' || *line == 'x' || *line == 'X')
				printf_helper_one(&line, &args, &count, &tmp);
			else if (*line == 'p' || *line == '%')
				printf_helper_two(&line, &args, &count, &tmp);
		}
		else
			count += ft_putchr(*line);
		line++;
	}
	va_end(args);
	return (count);
}
