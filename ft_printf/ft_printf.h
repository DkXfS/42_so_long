/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:43:28 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:43:30 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		only_dot;
	int		hash;
	int		space;
	int		plus;
}				t_flags;

int				ft_printf(const char *input, ...);
void			print_input(const char **in, va_list ap, int *n_char);
void			read_flags(const char **in, va_list ap, t_flags *flags);
void			print_conv(const char **in, va_list ap, int *n_char, t_flags f);
t_flags			init_flags(void);

size_t			ft_strlen(const char *s);
void			ft_put_abs_nbr(int n);
void			ft_put_unsigned(unsigned int n);

void			set_minus(const char **in, t_flags *f);
void			set_zero(const char **in, t_flags *f);
void			set_star(const char **in, va_list ap, t_flags *flags);
void			set_width(const char **in, t_flags *flags);
void			set_precision(const char **in, va_list ap, t_flags *flags);

void			set_hash(const char **in, t_flags *flags);
void			set_space(const char **in, t_flags *flags);
void			set_plus(const char **in, t_flags *flags);
void			save_len(int *ptr, int *n_char, t_flags flags);

int				printspaces(int len, ssize_t spacenum);
void			print_str(char *s, t_flags flags, int *n_char);
void			print_char(int c, t_flags flags, int *n_char);

void			print_int(int n, t_flags flags, int *n_char);
void			print_width(int *n_char, int num, char c);
int				ft_nbrlen(int n, int precision);
void			print_no_p(int n, t_flags flags, int *n_char, int n_len);
void			print_with_p(int n, t_flags flags, int *n_char, int n_len);
void			print_intsign(int *n_char, t_flags flags, int minus);

void			print_unsigned(unsigned int n, t_flags flags, int *n_char);
void			print_width(int *n_char, int num, char c);
int				ft_ulen(unsigned int n, t_flags flags);
void			print_u_no_p(unsigned int n, t_flags flags, int *n_char, int o);
void			print_u_with_p(unsigned int n, t_flags f, int *n_char, int o);

void			print_wildcard(t_flags flags, int *n_char);

void			printhex(unsigned int val, char alphacase, int *len, t_flags f);
void			printnum(unsigned long val, char alphacase, int *len, int t);
int				hexlen(unsigned long val);

void			print_ptr(void *ptr, int *len, t_flags flags);

char			*ft_ftoa(long double n, char *s, t_flags f);
void			print_float(long double n, t_flags f, int *n_char);

#endif
