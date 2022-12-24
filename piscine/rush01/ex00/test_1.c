/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:26:04 by tjan              #+#    #+#             */
/*   Updated: 2022/08/14 11:50:56 by tjan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	test_1_2(int tab[6][6], int type, int i, int j)
{
	if (type == 1)
	{
		if (check_possible(4, tab, i, 1))
			tab[i][1] = 4000;
		else
			return (0);
		if (check_possible(3, tab, i, 4))
			tab[i][4] = 300;
		else
			return (0);
	}
	else
	{
		if (check_possible(4, tab, 1, j))
			tab[1][j] = 4000;
		else
			return (0);
		if (check_possible(3, tab, 4, j))
			tab[4][j] = 300;
		else
			return (0);
	}
}

int	test_2_1(int tab[6][6], int type, int i, int j)
{
	if (type == 1)
	{
		if (check_possible(4, tab, i, 4))
			tab[i][4] = 4000;
		else
			return (0);
		if (check_possible(3, tab, i, 1))
			tab[i][1] = 300;
		else
			return (0);
	}
	else
	{
		if (check_possible(4, tab, 4, j))
			tab[4][j] = 4000;
		else
			return (0);
		if (check_possible(3, tab, 1, j))
			tab[1][j] = 300;
		else
			return (0);
	}
}

int	test_1_3(int tab[6][6], int type, int i, int j)
{
	if (type == 1)
	{
		if (check_possible(4, tab, i, 1))
			tab[i][1] = 4000;
		else
			return (0);
	}
	else
	{
		if (check_possible(4, tab, 1, j))
			tab[1][j] = 4000;
		else
			return (0);
	}
}

int	test_3_1(int tab[6][6], int type, int i, int j)
{
	if (type == 1)
	{
		if (check_possible(4, tab, i, 4))
			tab[i][4] = 4000;
		else
			return (0);
	}
	else
	{
		if (check_possible(4, tab, 4, j))
			tab[4][j] = 4000;
		else
			return (0);
	}
}
