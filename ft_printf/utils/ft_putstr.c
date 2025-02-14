#include "../includes/ft_printf.h"

int	ft_putstr(const char *str)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_putstr_len(const char *str, size_t len)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, len);
	return (len);
}
