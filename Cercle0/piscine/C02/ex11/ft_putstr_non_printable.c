/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:22:07 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/08 21:02:05 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert(unsigned int c)
{
	char	*basehexa;

	basehexa = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(basehexa[c / 16]);
	ft_putchar(basehexa[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			convert(str[i]);
		}
		else
		{
			write (1, &str[i], 1);
		}
		i++;
	}
}
