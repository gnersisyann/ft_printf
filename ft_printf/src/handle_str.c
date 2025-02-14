#include "../includes/ft_printf.h"

static void	handle_str_helper(int *count, char **str, t_combination *comb,
		int *len)
{
	if ((*comb).flags & '-')
	{
		*count += ft_putstr_len(*str, *len);
		*count += add_padding((*comb).width - *len, ' ');
	}
	else
	{
		if ((*comb).flags & FLAG_ZERO)
			*count += add_padding((*comb).width - *len, '0');
		else
			*count += add_padding((*comb).width - *len, ' ');
		*count += ft_putstr_len(*str, *len);
	}
}

int	handle_str(char *str, t_combination comb)
{
	int	count;
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (comb.precision >= 0 && comb.precision < len)
		len = comb.precision;
	if (comb.precision == 0 && !str)
		len = 0;
	count = 0;
	handle_str_helper(&count, &str, &comb, &len);
	return (count);
}

// if (!str && comb.precision > 0 && comb.precision < 6)
// 	str = "";