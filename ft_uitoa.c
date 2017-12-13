/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/13 13:29:20 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(long n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_uitoa(long n)
{
	int		i;
	long	nb;
	char	*str;

	nb = n;
	i = 0;
	if (!(str = ft_strnew(get_length(n))))
		return (0);
	if (nb == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
