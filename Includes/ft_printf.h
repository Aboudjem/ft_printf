/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:12:24 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/02 00:35:07 by aboudjem         ###   ########.fr       */
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
	char					*print;
	int						i;
	int						j;
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

void			init_start(t_conv *t);
int				ft_wstrcmp(const wchar_t *s1, const wchar_t *s2);
void			no_conv(const char *s, int i, t_conv *t, t_flags f);
int				count_char(const char *s, int i);
void			no_fill_nodot(t_conv *t, t_flags f);
void			noconv_join(t_conv *t, t_flags f);
int				is_flag(const char *s, int i);

/*
 ** ft_printf.c
*/
void	get_conv(const char *s, int i, t_conv *t, t_flags f);
void	modif_length(t_flags *f, t_conv *t);

void			get_length_o(t_flags f, t_conv *t);
void	join_neg(t_conv *t, t_flags f);

int				ft_printf(const char *format, ...);
void			get_padding(const char *s, int i, t_flags *f);
void			get_precision(const char *s, int i, t_flags *f);
char			next_conv(const char *s, int i);
void			len_return(t_conv *t, t_flags f);
void			print_type(t_conv t, t_flags f, const char *s, int i);
void			get_length(t_flags *f, t_conv *t);
void			which_conv(const char *s, int i, t_conv *t, t_flags f);
void			which_length(const char *s, int i, t_flags *f);
void			which_flags(const char *s, int i, t_conv t, t_flags *f);
void			get_length_u(t_flags *f, t_conv *t);
/*
 ** ft_conv_c.c
*/
void			conv_c(t_conv *t, t_flags f);
/*
 ** ft_conv_d.c
*/
void			conv_d(t_conv *t, t_flags f);
t_flags			handle_d(t_flags f);
void			nb_sign(t_conv *t, t_flags f);
char			*handle_zero(t_conv t, t_flags f);

/*
 ** ft_conv_uoxX.c
*/
void			conv_x(t_conv *t, t_flags f);
void			conv_o(t_conv *t, t_flags f);
char			*revert_str(char *str, int i);
void			ft_hexa(t_conv *t);
void			ft_octal(t_conv *t);
void			ft_hashtag(t_conv *t, t_flags f);

/*
 ** ft_conv_u.c
*/
void			nb_sign_u(t_conv *t, t_flags f);
void			conv_u(t_conv *t, t_flags f);
void			u_fill_space(t_conv *t, t_flags f);
void			u_fill_zero(t_conv *t, t_flags f);
/*
 ** ft_conv_p.c
*/
void			conv_p(t_conv *t, t_flags f);
void			p_join(t_conv *t, t_flags f);
/*
 ** ft_conv_CS.c
*/
void			one_bytes(unsigned long int c, t_conv *t);
void			two_bytes(unsigned long int c, t_conv *t);
void			three_bytes(unsigned long int c, t_conv *t);
void			four_bytes(unsigned long int c, t_conv *t);
void			how_long(unsigned long int c, t_conv *t);
void			how_long2(unsigned long int c, t_conv *t);
int				len_wc(unsigned int c);
void			conv_wc(unsigned long int c, t_conv *t);
void			conv_ws(t_conv *t, t_flags f);
void			s_join(t_conv *t, t_flags f);
void			s_fill_zero(t_conv *t, t_flags f);
void			s_fill_space(t_conv *t, t_flags f);
void			p_fill_zero(t_conv *t, t_flags f);
void			p_fill_space(t_conv *t, t_flags f);
void			s_fill_nodot(t_conv *t, t_flags f);
void			p_fill_nodot(t_conv *t, t_flags f);
void			s_nodot_join(t_conv *t, t_flags f);
int				s_pre(t_conv *t, t_flags f);

/*
 ** ft_utils.c
*/
char			*ft_litoa(unsigned long long int n);
void			*ft_strset(int c, size_t len);
int				ft_len_int(int nbr);
void			display(t_flags f);
void			init_flags(t_flags *f);
void			ft_stroupper(char *s);
void			ft_free(t_conv *t);

/*
 ** ft_conv_percent.c
*/
void			conv_percent(t_conv *t, t_flags f);
/*
 ** ft_conv_s.c
*/

void			conv_s(t_conv *t, t_flags f);
/*
 ** ft_conv_c.c
*/
void			join(t_conv *t, t_flags f);
void			init(t_conv *t);
void			fill_nodot(t_conv *t, t_flags f);
void			x_fill_nodot(t_conv *t, t_flags f);
void			fill_space(t_conv *t, t_flags f);
void			fill_zero(t_conv *t, t_flags f);
#endif
