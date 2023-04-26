/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:12:37 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/24 16:12:37 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_double(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && str_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_number(char *av)
{
	int i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-') && (av[i + 1] != '\0'))
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0')
		return (1);
	else
		return (0);
}

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	parsing(char **av)
{
	int i;
	int zero;

	zero = 0;
	i = 0;
	if (check_double(av))
	{
		ft_printf("Error\n");
		exit(0);
	}
	while (av[i])
	{
		zero += arg_is_zero(av[i]);
		if (is_number(av[i]))
		{
			ft_printf("Error\n");
			exit(0);
		}
		i++;
	}
	if (zero > 1)
	{
		ft_printf("Error\n");
		exit(0);
	}
	return (0);
}
