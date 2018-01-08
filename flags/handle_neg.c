/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_neg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:26:08 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/08 15:25:08 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define ABS(value) value < 0 ? -value : value

static char	*remove_useless_flag(char *flag, int idx)
{
	if (ft_isdigit(flag[idx + 1]) && flag[idx + 1] != '0')
		flag = replacestr(flag, ft_itoa(ft_atoi(&flag[idx])), "");
	else if (flag[idx + 1] == '0')
		flag = replacestr(flag, add_end("-", "0"), "");
	else
		flag = replacestr(flag, "-", "");
	return (flag);
}

static char	*update_nb(char *flag, int *nb)
{
	int		j;

	j = -1;
	while (flag[++j])
		if (ft_isdigit(flag[j]) && flag[j] != 0)
		{
			if (*nb == 0)
				*nb = ft_atoi(&flag[j]);
			flag = replacestr(flag, ft_itoa(ft_atoi(&flag[j])), "");
			break ;
		}
	return (flag);
}

char		*handle_neg(char *flag, char *ret)
{
	int		i;
	int		nb;

	i = -1;
	while (flag[++i])
		if (flag[i] == '-')
		{
			nb = ABS(ft_atoi(&flag[i + 1]));
			flag = update_nb(flag, &nb);
			while (ft_strlen(ret) < (size_t)(nb))
				ret = add_end(ret, " ");
			flag = remove_useless_flag(flag, i);
			i = -1;
			while (flag[++i])
				if (flag[i] == '0' && !ft_isdigit(flag[i - 1]))
					flag = replacestr(flag, get_0_param(&flag[i]), "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}
