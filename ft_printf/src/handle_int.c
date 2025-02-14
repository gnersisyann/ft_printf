#include "../includes/ft_printf.h"

int	handle_int(int n, t_combination comb)
{
	char	*str;
	int		count;

	str = ft_itoa(n);
	if (!str)
		return (0);
	count = apply_flags(str, comb, 1);
	free(str);
	return (count);
}
