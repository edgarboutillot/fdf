/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:03:06 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/19 12:42:46 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_recursive(unsigned int nbr, char *base, unsigned int b)
{
	if (nbr > b - 1)
		ft_putnbr_recursive(nbr / b, base, b);
	ft_putchar(base[nbr % b]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	b;
	unsigned int	n;

	b = check_base(base);
	if (b > 1)
	{
		if (nbr < 0)
		{
	i = 3;
			n = -nbr;
			ft_putchar('-');
		}
		else
			n = nbr;
		ft_putnbr_recursive(n, base, b);
	}
}


int main() {
//  char a[] = "      \t \v ---++--1231dsf4324";
//  printf("%d", ft_atoi(a));
ft_putnbr_base(-1246546547, "0123456789");
printf("\n");
ft_putnbr_base(12, "01");
printf("\n");
ft_putnbr_base(-12, "0123456789abcdefghijk");
printf("\n");
ft_putnbr_base(-2147483648, "0123456789");
printf("\n");
  return 0;
}
