/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:57:06 by edboutil          #+#    #+#             */
/*   Updated: 2023/01/26 14:10:47 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int n1 = atoi(av[1]);
	int n2 = atoi(av[3]);

	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf("%d", n1 + n2);
		else if (av[2][0] == '-')
			printf("%d", n1 - n2);
		else if (av[2][0] == '/')
			printf("%d", n1 / n2);
		else if (av[2][0] == '*')
			printf("%d", n1 * n2);
		else if (av[2][0] == '%')
			printf("%d", n1 % n2);
	}
	printf("\n");
	return (0);
}
