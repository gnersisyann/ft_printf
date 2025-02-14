#include "../includes/ft_printf.h"

int	handle_ptr(void *ptr, t_combination comb)
{
	char	*str;
	int		count;

	count = 0;
	if (!ptr)
	{
		str = ft_strdup("0");
		if (!str)
			return (0);
	}
	else
	{
		str = ft_itoa_base_ptr((unsigned long)ptr, 16);
		if (!str)
			return (0);
	}
	count += apply_flags(str, comb, 0);
	free(str);
	return (count);
}
