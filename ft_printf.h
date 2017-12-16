/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:10:48 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/16 13:29:37 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "libft.h"

int			ft_printf(const char *format, ...);
char		*handle_flags(char *length_flag, char *flag, va_list *args);
char		*handle_conversion(char *flag, char *ret);
char		*replacestr(char *dest, char *flag, char *content);
char		*add_begin(char *str, char *add);
char		*add_end(char *str, char *add);
char		*get_flag(char *str);
char		*handle_diese(char *flag, char *ret);
char		*handle_neg(char *flag, char *ret);
char		*handle_zero(char *flag, char *ret);
char		*handle_digit(char *flag, char *ret);
char		*handle_plus(char *flag, char *ret);
char		*handle_space(char *flag, char *ret);
char		*handle_precision(char *flag, char *ret);
char		*get_0_param(char *str);
int			get_index(const char *haystack, const char *needle);
char		*ft_uitoa(intmax_t n);
long long 	ft_atol(const char *str);
char		*ft_lltoa_base(uintmax_t n, int base);
char		*ft_unsitoa(unsigned int n);
char		*ft_ultoa(unsigned long n);
char		*ft_llutoa(unsigned long long n);

#endif
