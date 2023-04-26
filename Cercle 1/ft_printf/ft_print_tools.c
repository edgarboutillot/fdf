/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:27:52 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/19 14:56:40 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, len);
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', len);
		nb = -n;
	}
	else
		nb = n;
	ft_putnbr_base(nb, BASE_DEC, 10, len);
}

void	ft_putnbr_base(LLU_INT n, char *base, int len_base, int *len)
{
	if (n >= (LLU_INT)len_base)
		ft_putnbr_base(n / len_base, base, len_base, len);
	ft_putchar(base[n % len_base], len);
}
