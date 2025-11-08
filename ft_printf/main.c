/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:22:08 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/24 15:11:15 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

void	test_get_flags(int ac, char **av)
{
	char		*flags;
	const char	**str;

	(void)ac;
	str = (const char **)av + 2;
	flags = ft_get_flags(str);
	printf("%s %s", flags, *str);
	free(flags);
}

void	test_get_number(int ac, char **av)
{
	int			n;
	const char	**str;

	(void)ac;
	str = (const char **)av + 2;
	n = ft_get_number(str);
	printf("%d %s", n, *str);
}

int	main(int ac, char **av)
{
	//char	str[10];

	//ft_printf("'%5d %5u %5c %5s'", 0, 0, '0', "");
	//ft_printf("'%p'\n", str);
	//printf("'%p'\n", NULL);
	//ft_printf("'%+d'\n", 0);
	
	//char	*str = "%-8.s";
	//printf("\"[%d]\"\n", printf(str, NULL));
	//printf("\"[%d]\"\n\n", ft_printf(str, NULL));

	if (ac < 2)
		return (-1);
	if (strcmp(av[1], "ft_get_flags") == 0)
		test_get_flags(ac, av);
	else if (strcmp(av[1], "ft_get_number") == 0)
		test_get_number(ac, av);
	else
	{
		int		printed_count;

		if (ac > 5 && strcmp(av[5], "NULL") == 0)
			av[5] = NULL;

		printed_count = 0;
		if (ac == 2)
			printed_count = ft_printf(av[1]);
		if (ac == 3)
			printed_count = ft_printf(av[1], atoi(av[2]));
		if (ac == 4)
			printed_count = ft_printf(av[1], atoi(av[2]), (unsigned int)atoi(av[3]) + 2147483648);
		if (ac == 5)
			printed_count = ft_printf(av[1], atoi(av[2]), (unsigned int)atoi(av[3]) + 2147483648, av[4][0]);
		if (ac == 6)
			printed_count = ft_printf(av[1], atoi(av[2]), (unsigned int)atoi(av[3]) + 2147483648, av[4][0], av[5]);
		if (ac == 7)
			printed_count = ft_printf(av[1], atoi(av[2]), (unsigned int)atoi(av[3]) + 2147483648, av[4][0], av[5], av[6]);

		write(1, "[", 1);
		ft_putnbr_fd(printed_count, 1);
		write(1, "]", 1);
	}
}
