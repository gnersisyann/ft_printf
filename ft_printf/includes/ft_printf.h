#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_MINUS 1  // '-'
# define FLAG_ZERO 2   // '0'
# define FLAG_HASH 4   // '#'
# define FLAG_PLUS 8   // '+'
# define FLAG_SPACE 16 // ' ' (space)

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_combination
{
	char		type;
	char		flags;
	int			width;
	int			precision;
	int			next_index;
}				t_combination;

int				ft_printf(const char *line, ...);

int				ft_putchr(int c);
int				ft_putnbr(int n);
int				ft_putstr(const char *str);
int				ft_putstr_len(const char *str, size_t len);
char			*ft_itoa_base(long long n, int base);
char			*ft_itoa_base_ptr(unsigned long n, int base);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			*ft_itoa_base_hex(unsigned int n, int base);
char			*ft_strdup(const char *s);
int				ft_putnbr_unsigned(unsigned int n);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
int				get_effective_length(char *str, t_combination comb, int sign);
int				handle_zero_flag(char *str, t_combination comb, int sign);
int				handle_left_align(char *str, t_combination comb, int len,
					int sign);
int				handle_right_align(char *str, t_combination comb, int len,
					int sign);

// bonus
t_combination	parse_format(const char *format, va_list *args);
int				apply_flags(char *str, t_combination comb, int is_signed);
int				add_padding(int width, char c);
int				add_precision(char *str, t_combination comb);
int				add_prefix(int sign, t_combination comb, char *str);
int				get_sign(char *str, int is_signed, t_combination comb);

int				handle_char(char c, t_combination comb);
int				handle_str(char *str, t_combination comb);
int				handle_int(int n, t_combination comb);
int				handle_unsigned(unsigned int n, t_combination comb);
int				handle_hex(unsigned int n, t_combination comb);
int				handle_ptr(void *ptr, t_combination comb);

#endif
