#include "../includes/ft_printf.h"

static size_t	digitcount_base(long long n, int base)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0 && base == 10)
		size++;
	while (n)
	{
		size++;
		n /= base;
	}
	return (size);
}

static void	fill_base(char *res, long long n, int base, const char *digits)
{
	int	index;

	index = digitcount_base(n, base);
	res[index--] = '\0';
	if (n < 0 && base == 10)
	{
		res[0] = '-';
		n = -n;
	}
	while (n)
	{
		res[index--] = digits[n % base];
		n /= base;
	}
}

char	*ft_itoa_base(long long n, int base)
{
	char		*res;
	const char	*digits;

	if (base == 0 || base < -16 || base > 16 || base == -1 || base == 1)
		return (NULL);
	if (base > 0)
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	if (base < 0)
		base *= -1;
	if (n == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(digitcount_base(n, base) + 1);
	if (!res)
		return (NULL);
	fill_base(res, n, base, digits);
	return (res);
}
