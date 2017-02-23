/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:12:24 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 03:43:58 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <locale.h>

typedef struct	s_type
{
	unsigned long long int	u;
	long long				d;
	unsigned int			c;
	wchar_t					*w;
	va_list					arguments;
	char					*s;
	void					*p;
	int						len;
	int						count;
	int						neg;
	char					*space;
	char					*zero;
	char					*nb;
	char					*sign;
	int						len_d;
	int						len_space;
	int						len_zero;
	int						len_return;
	char					conv;
	char					*str;
}				t_conv;

typedef struct	s_flags
{
	int zero;
	int space;
	int neg;
	int plus;
	int prcnt;
	int hash;
	int dot;
	int l;
	int ll;
	int h;
	int hh;
	int j;
	int z;
	int pad;
	int pre;
	int negdot;
	int champs;
	int len_pre;
	int len_pad;
	int u_used;
	int d_used;
}				t_flags;

int				ft_wstrcmp(const wchar_t *s1, const wchar_t *s2);
void			no_conv(const char *s, int i, t_conv *type, t_flags flags);
int				count_char(const char *s, int i);
void			no_fill_nodot(t_conv *type, t_flags flags);
void			noconv_join(t_conv *type, t_flags flags);
int				is_flag(const char *s, int i);

/*
 ** ft_printf.c
*/
void			get_length_o(t_flags flags, t_conv *type);

int				ft_printf(const char *format, ...);
void			get_padding(const char *s, int i, t_flags *flags);
void			get_precision(const char *s, int i, t_flags *flags);
char			next_conv(const char *s, int i);
void			len_return(t_conv *type, t_flags flags);
void			print_type(t_conv type, t_flags flags, const char *s, int i);
void			get_length(t_flags *flags, t_conv *type);
t_conv			which_conv(const char *s, int i, t_conv type, t_flags flags);
t_flags			which_length(const char *s, int i, t_flags flags);
t_flags			which_flags(const char *s, int i, t_conv type);
void			get_length_u(t_flags *flags, t_conv *type);
/*
 ** ft_conv_c.c
*/
void			conv_c(t_conv *type, t_flags flags);
/*
 ** ft_conv_d.c
*/
void			conv_d(t_conv *type, t_flags flags);
t_flags			handle_d(t_flags flags);
void			nb_sign(t_conv *type, t_flags flags);
char			*handle_zero(t_conv type, t_flags flags);

/*
 ** ft_conv_uoxX.c
*/
void			conv_x_bigx(t_conv *type, t_flags flags);
void			conv_o_bigo(t_conv *type, t_flags flags);
char			*revert_str(char *str, int i);
void			ft_hexa(t_conv *type);
void			ft_octal(t_conv *type);
void			ft_hashtag(t_conv *type, t_flags flags);

/*
 ** ft_conv_u.c
*/
void			nb_sign_u(t_conv *type, t_flags flags);
void			conv_u(t_conv *type, t_flags flags);
/*
 ** ft_conv_p.c
*/
void			conv_p(t_conv *type, t_flags flags);
void			p_join(t_conv *type, t_flags flags);
/*
 ** ft_conv_CS.c
*/
void			one_bytes(unsigned long int c, t_conv *type);
void			two_bytes(unsigned long int c, t_conv *type);
void			three_bytes(unsigned long int c, t_conv *type);
void			four_bytes(unsigned long int c, t_conv *type);
void			how_long(unsigned long int c, t_conv *type);
void			how_long2(unsigned long int c, t_conv *type);

int				len_c(unsigned int c);
void			conv_wc(unsigned long int c, t_conv *type);
void			conv_ws(t_conv *type, t_flags flags);
void			s_join(t_conv *type, t_flags flags);
void			s_fill_zero(t_conv *type, t_flags flags);
void			s_fill_space(t_conv *type, t_flags flags);
void			s_fill_nodot(t_conv *type, t_flags flags);
void			s_fill_nodot2(t_conv *type);
int				s_pre(t_conv *type, t_flags flags);

/*
 ** ft_utils.c
*/
char			*ft_litoa(unsigned long long int n);
void			*ft_strset(int c, size_t len);
int				ft_len_int(int nbr);
void			display(t_flags flags);
void			init_flags(t_flags *flags);
void			ft_stroupper(char *s);
void			ft_free(t_conv *type);

/*
 ** ft_conv_percent.c
*/
void			conv_percent(t_conv *type, t_flags flags);
/*
 ** ft_conv_s.c
*/

void			conv_s(t_conv *type, t_flags flags);
/*
 ** ft_conv_c.c
*/
void			join(t_conv *type, t_flags flags);
void			init(t_conv *type);
void			fill_nodot(t_conv *type, t_flags flags);
void			fill_space(t_conv *type, t_flags flags);
void			fill_zero(t_conv *type, t_flags flags);
#endif
