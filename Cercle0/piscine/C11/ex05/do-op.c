/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:58:18 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/25 18:38:01 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	do_op(int a, char op, int b)
{
	int	result;

	result = 0;
	if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '/')
	{
		if (b == 0)
			return ((void)write(1, "Stop : division by zero\n", 24));
		result = a / b;
	}
	else if (op == '*')
		result = a * b;
	else if (op == '%')
	{
		if (b == 0)
			return ((void)write(1, "Stop : modulo by zero\n", 22));
		result = a % b;
	}
	ft_putnbr(result);
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		do_op(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]));
	}
	return (0);
}
