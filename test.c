/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/12 14:18:58 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	//setlocale(LC_ALL, "");
/*	int e = 7;
	printf("Length: %d\n", ft_printf("%d %-20S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫", "haha", "abcdef", 97, 2147483649, &e));
	printf("Length: %d\n",    printf("%d %-20S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫", "haha", "abcdef", 97, 2147483649, &e));
	ft_printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95);
	printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95);
	printf("Length 2: %d\n", ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	printf("Length 2: %d\n", printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	printf("Length 3: %d\n", ft_printf("me/ %10C test\n", L'à'));
	printf("Length 3: %d\n", printf("em/ %10C test\n", L'à'));
	printf("Length 4: %d\n", ft_printf("Test/ %s aaaaaaa\n", NULL));
	printf("Length 4: %d\n", printf("Test/ %s aaaaaaa\n", NULL));
	printf("Length 5: %d\n", ft_printf("%ld%ld\n", 0, 42));
	printf("Length 5: %d\n", printf("%ld%ld\n", 0, 42));*/
	printf("Length 6: %d\n", ft_printf("%s%p%d%d%p%s%p%p%s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c"));
	printf("Length 6: %d\n", printf("%s%p%d%d%p%s%p%p%s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c"));
	return (0);
}
