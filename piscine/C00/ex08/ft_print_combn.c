/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:21:01 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/05 11:25:32 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printing(int tab[], int n)
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (tab[0] != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	ft_recursive(int tab[], int n, int i)
{
	if (i == 0)
	{
		tab[i] = 0;
	}
	else
	{
		tab[i] = tab[i - 1] + 1;
	}
	while (tab[i] < 11 - n + i)
	{
		if (i == n - 1)
		{
			ft_printing(tab, n);
		}
		else
		{
			ft_recursive(tab, n, i + 1);
		}
		tab[i] += 1;
	}
}

void	ft_print_combn(int n)
{
	int	array[10];

	ft_recursive(array, n, 0);
}
