/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:05:27 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/05 12:43:42 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr(char const *str)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
