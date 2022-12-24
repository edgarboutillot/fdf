/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb22.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:32:45 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/05 10:19:37 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i1;
	int	i2;

	i1 = 0;
	while (i1 <= 98)
	{
		i2 = i1 + 1;
		while (i2 <= 99)
		{
			ft_putchar(48 + (i1 / 10));
			ft_putchar(48 + (i1 % 10));
			write(1, " ", 1);
			ft_putchar(48 + (i2 / 10));
			ft_putchar(48 + (i2 % 10));
			if (i1 < 98 || i2 < 99)
			{
				write(1, ", ", 2);
			}
			i2++;
		}
		i1++;
	}
}
