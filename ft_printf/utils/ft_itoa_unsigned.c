#include "../includes/ft_printf.h"

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

static void	fill_unsigned(char *res, unsigned int n, int index)
{
	res[index--] = '\0';
	while (n)
	{
		res[index--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*res;
	size_t	digit_count;

	digit_count = digitcount_unsigned(n);
	if (n == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(digit_count + 1);
	if (!res)
		return (NULL);
	fill_unsigned(res, n, digit_count);
	return (res);
}
