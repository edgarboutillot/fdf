/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:47:50 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/04 19:57:37 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_megachar(char i1, char i2, char i3)
{
	write(1, &i1, 1);
	write(1, &i2, 1);
	write(1, &i3, 1);
	if (i1 != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = '0';
	while (i1 <= '7')
	{
		i2 = i1 + 1;
		while (i2 <= '8')
		{
			i3 = i2 + 1;
			while (i3 <= '9')
			{
				ft_put_megachar(i1, i2, i3);
				i3++;
			}
			i2++;
		}
		i1++;
	}
}
