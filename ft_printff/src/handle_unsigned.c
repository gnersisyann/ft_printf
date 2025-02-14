#include "../includes/ft_printf.h"

int	handle_unsigned(unsigned int n, t_combination comb)
{
	char	*str;
	int		count;

	str = ft_itoa_unsigned(n);
	if (!str)
		return (0);
	count = apply_flags(str, comb, 0);
	free(str);
	return (count);
}
