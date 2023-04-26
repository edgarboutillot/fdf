/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:58:14 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/18 19:20:36 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_puzzle(int *tab, int	*n_tot)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	(*n_tot)++;
}

int	ft_line(int	*tab, int col, int line)
{
	while (col--)
	{
		if (line == tab[col])
			return (0);
	}
	return (1);
}

int	ft_diag(int *tab, int col, int line)
{
	int	i;

	i = 1;
	while (line - 1 >= 0 && col - i >= 0)
	{
		if (line - i == tab[col - i])
			return (0);
		i++;
	}
	i = 1;
	while (line + i < 10 && col - i >= 0)
	{
		if (line + i == tab[col - i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_recursive(int *tab, int *n_tot, int col)
{
	int	line;

	line = 0;
	if (col == 10)
		ft_print_puzzle(tab, n_tot);
	while (line < 10)
	{
		if (ft_line(tab, col, line) && ft_diag(tab, col, line))
		{
			tab[col] = line;
			if (ft_recursive(tab, n_tot, col + 1))
				return (1);
		}
		line++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	n_tot;
	int	tab[10];

	n_tot = 0;
	ft_recursive(tab, &n_tot, 0);
	return (n_tot);
}
