/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:05:05 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/24 17:05:06 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(const char *str)
{
	int						i;
	long long unsigned int	result;
	int						sign;

	i = 0;
	result = 0;
	sign = 1;
	while (((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - 48);
		if (result > __LONG_LONG_MAX__)
			return (0 - (sign == 1));
	}
	return ((int)result * sign);
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_send_bits(pid, av[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
