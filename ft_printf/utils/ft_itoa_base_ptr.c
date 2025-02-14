#include "../includes/ft_printf.h"

static size_t	digitcount_base_ptr(unsigned long n, int base)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= base;
	}
	return (size);
}

static void	fill_base_ptr(char *res, unsigned long n, int base,
		const char *digits)
{
	int	index;

	index = digitcount_base_ptr(n, base);
	res[index--] = '\0';
	while (n)
	{
		res[index--] = digits[n % base];
		n /= base;
	}
}

char	*ft_itoa_base_ptr(unsigned long n, int base)
{
	const char	*digits;
	char		*res;

	digits = "0123456789abcdef";
	if (base != 16)
		return (NULL);
	res = (char *)malloc(digitcount_base_ptr(n, base) + 1);
	if (!res)
		return (NULL);
	fill_base_ptr(res, n, base, digits);
	return (res);
}
