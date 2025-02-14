#include "../includes/ft_printf.h"

int	handle_hex(unsigned int n, t_combination comb)
{
	char	*str;
	int		count;

	if (comb.type == 'X')
		str = ft_itoa_base(n, -16);
	else
		str = ft_itoa_base(n, 16);
	if (!str)
		return (0);
	count = apply_flags(str, comb, 0);
	free(str);
	return (count);
}
