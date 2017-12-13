/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:52:38 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/13 13:33:34 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_ctos(char c)
{
	char	*buf;

	if (!(buf = ft_strnew(1)))
		return (0);
	buf[0] = c;
	return (buf);
}

wchar_t	*ft_CtoS(wchar_t c)
{
	wchar_t	*buf;

	if (!(buf = (wchar_t*)malloc(sizeof(wchar_t) * 2)))
		return (0);
	buf[0] = c;
	return (buf);
}
