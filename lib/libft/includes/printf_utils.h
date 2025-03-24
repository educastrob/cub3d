#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define OCTAL_BASE "01234567"
# define DEC_BASE "0123456789"
# define HEX_U_BASE "0123456789ABCDEF"
# define HEX_L_BASE "0123456789abcdef"

# define PTR_HEX_L_PREFIX "0x"
# define HEX_U_PREFIX "0X"
# define OCT_PREFIX "0"
# define MINUS '-'
# define PLUS '+'
# define SPACE ' '

# define MINUS_FLAG_MASK 0b000001
# define ZERO_FLAG_MASK 0b000010
# define PLUS_FLAG_MASK 0b000100
# define SPACE_FLAG_MASK 0b001000
# define HASH_FLAG_MASK 0b010000

typedef struct s_element
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			type;
	int				fd;
}					t_element;

int					ft_printf_putstr(const char *str, t_element element);
int					ft_printf_putchar(const char c, t_element element);
int					ft_printf_putnbr(int n, t_element element);
int					ft_printf_putnbr_b(unsigned long nbr, const char *base,
						t_element element);
int					ft_printf_putpointer(const void *ptr, t_element element);
int					ft_printf_isvalid(char c);
int					ft_printf_isflag(char c);
int					ft_printf_istype(char c);
unsigned char		ft_printf_get_flag(char c);
int					ft_printf_atoi(const char **nptr);
void				ft_printf_print_spaces(int spaces, char c, int fd);
int					ft_printf_printnbr(char *str_n, int len, t_element element);
void				ft_printf_strcpy(char *dest, char *source, int len);

#endif
