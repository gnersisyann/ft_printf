#include "../includes/ft_printf.h"

static size_t	digitcount(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static size_t	digitcount_unsigned(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	case_handler(int *n, size_t *printed)
{
	if (*n == 0)
	{
		write(1, "0", 1);
		++(*printed);
		return ;
	}
	if (*n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*printed) += 11;
		return ;
	}
	if (*n < 0)
	{
		write(1, "-", 1);
		++(*printed);
		*n *= -1;
	}
}

int	ft_putnbr(int n)
{
	char	c;
	size_t	digits;
	size_t	i;
	size_t	tmp;
	size_t	printed;

	printed = 0;
	case_handler(&n, &printed);
	if (n == 0 || n == -2147483648)
		return (printed);
	digits = digitcount(n);
	tmp = digits;
	i = 1;
	while (--tmp)
		i *= 10;
	while (n || digits)
	{
		c = (n / i) + '0';
		write(1, &c, 1);
		n %= i;
		i /= 10;
		digits--;
		printed++;
	}
	return (printed);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	size_t	digits;
	size_t	i;
	size_t	tmp;
	size_t	printed;

	printed = 0;
	if (n == 0)
		return (write(1, "0", 1));
	digits = digitcount_unsigned(n);
	tmp = digits;
	i = 1;
	while (--tmp)
		i *= 10;
	while (n || digits)
	{
		c = (n / i) + '0';
		write(1, &c, 1);
		n %= i;
		i /= 10;
		digits--;
		printed++;
	}
	return (printed);
}
