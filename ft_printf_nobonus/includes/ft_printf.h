#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *line, ...);

int		ft_putchr(int c);
int		ft_putnbr(int n);
int		ft_putstr(const char *str);
int		ft_putstr_len(const char *str, size_t len);
char	*ft_itoa_base(long long n, int base);
char	*ft_itoa_base_ptr(unsigned long n, int base);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_strdup(const char *s);
int		ft_putnbr_unsigned(unsigned int n);
size_t	ft_strlen(const char *s);

#endif