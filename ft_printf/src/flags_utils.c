#include "../includes/ft_printf.h"

int	get_effective_length(char *str, t_combination comb, int sign)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	if (comb.precision > len)
		len = comb.precision;
	if (sign)
		len++;
	if ((comb.flags & FLAG_HASH) && (comb.type == 'x' || comb.type == 'X'))
		len += 2;
	return (len);
}

int	apply_flags(char *str, t_combination comb, int is_signed)
{
	int	len;
	int	sign;
	int	has_prefix;

	sign = get_sign(str, is_signed, comb);
	has_prefix = comb.type == 'p' || ((comb.flags & FLAG_HASH)
			&& (comb.type == 'x' || comb.type == 'X'));
	if (comb.type != 'p' && (comb.flags & FLAG_HASH) && (comb.type == 'x'
			|| comb.type == 'X') && str[0] == '0')
		comb.flags &= ~FLAG_HASH;
	if (comb.precision == 0 && str[0] == '0' && comb.type != 'p')
		str = "";
	if (comb.flags & FLAG_MINUS)
		comb.flags &= ~FLAG_ZERO;
	if (comb.precision >= 0)
		comb.flags &= ~FLAG_ZERO;
	if (comb.flags & FLAG_SPACE && comb.flags & FLAG_PLUS)
		comb.flags &= ~FLAG_SPACE;
	len = get_effective_length(str, comb, sign);
	if (comb.flags & FLAG_MINUS)
		return (handle_left_align(str, comb, len, sign));
	else if (comb.flags & FLAG_ZERO && comb.precision < 0)
		return (handle_zero_flag(str, comb, sign));
	else
		return (handle_right_align(str, comb, len, sign));
}
