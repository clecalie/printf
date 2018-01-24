/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:51:46 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/24 14:45:00 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_temp(char *ret, char **temp, char flag_letter)
{
	*temp = 0;
	if (ret == NULL && (flag_letter == 's' || flag_letter == 'S'))
		ret = ft_strdup("(null)");
	else if (ret && ft_strequ(ret, "-1") && ft_strchr("CS", flag_letter))
		return (ret);
	else if (ret && ret[0] == '\0' && ft_strchr("cC", flag_letter))
	{
		*temp = ft_strdup("@");
		ft_strdel(&ret);
		ret = ft_strdup("@");
	}
	else if (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)"))
	{
		*temp = ft_strdup(ret);
		ret = ft_update(&ret, ft_strndup(ret, (ft_strlen(ret) / 3)));
	}
	else if (!ft_strchr("sSpdDioOuUxXcC%", flag_letter))
	{
		ft_strdel(&ret);
		ret = ft_ctos(flag_letter);
	}
	return (ret);
}

static void	print_content(char *ret, char *temp,
		char *conversion, char flag_letter)
{
	int		j;

	if (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)")
			&& !ft_strequ(ret, "@"))
		manip_sc_up(conversion, ret, temp);
	else if (ft_strchr("cC", flag_letter) && temp && temp[0] == '@')
	{
		j = 0;
		while (conversion[j])
		{
			if (conversion[j] == '@')
				ft_putchar(0);
			else
				ft_putchar(conversion[j]);
			j++;
		}
	}
	else
		ft_putstr(conversion);
}

static int	apply_conversion(char **flag, char **ret, char **temp, char **str)
{
	char	*t_ret;
	char	*t_flag;
	char	*conversion;
	char	flag_letter;
	int		len;

	t_ret = ft_strdup(*ret);
	t_flag = ft_strdup(*flag);
	flag_letter = t_flag[ft_strlen(t_flag) - 1];
	conversion = handle_conversion(*flag, *ret);
	*str = replacestr(*str, t_flag, ft_strdup(conversion));
	print_content(t_ret, *temp, conversion, flag_letter);
	ft_strdel(temp);
	len = ft_strlen(conversion);
	if (len > 0)
		ft_strdel(&conversion);
	ft_strdel(&t_ret);
	return (len);
}

char		*apply_flag(char *flag, char *str, int *i, va_list *args)
{
	char	*temp;
	char	*ret;
	char	*length_f;

	length_f = get_length_flag(flag);
	ret = handle_flags(length_f, flag, args);
	ft_strdel(&length_f);
	if (ft_strchr("cs", flag[ft_strlen(flag) - 1]) && ft_strchr(length_f, 'l'))
		flag[ft_strlen(flag) - 1] = ft_toupper(flag[ft_strlen(flag) - 1]);
	if (ft_strchr("CS", flag[ft_strlen(flag) - 1])
			&& ret && !valid_unicode(ret))
	{
		ft_strdel(&ret);
		return ("-1");
	}
	ret = get_temp(ret, &temp, flag[ft_strlen(flag) - 1]);
	if (ret && (ft_strequ(ret, "-1")) &&
			ft_strchr("CS", flag[ft_strlen(flag) - 1]))
	{
		ft_strdel(&length_f);
		ft_strdel(&temp);
		return (ret);
	}
	*i += apply_conversion(&flag, &ret, &temp, &str) - 1;
	return (str);
}
