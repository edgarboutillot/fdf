/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:51:05 by tjan              #+#    #+#             */
/*   Updated: 2022/08/14 12:21:42 by tjan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	test_2_2(int tab[6][6], int type, int i, int j)
{
	if (type == 1)
	{
		if (tab[i][1] == 4000 || tab[i][4] == 4000)
			return (0);
		else
		{
			tab[i][1] = tab[i][1] % 1000;
			tab[i][4] = tab[i][4] % 1000;
		}
		if (check_possible(3, tab, i, 1) || check_possible(3, tab, i, 4))
		{
			if (check_possible(3, tab, i, 2))
				tab[i][2] = tab[i][2] - 300;
			if (check_possible(3, tab, i, 3))
				tab[i][3] = tab[i][3] - 300;
		}
		else
			return (0);
	}
	else
		test_2_2_bis(tab, j);
}

int	test_2_2_bis(int tab[6][6], int j)
{
	if (tab[1][j] == 4000 || tab[4][j] == 4000)
		return (0);
	else
	{
		tab[1][j] = tab[1][j] % 1000;
		tab[4][j] = tab[4][j] % 1000;
	}
	if (check_possible(3, tab, 1, j) || check_possible(3, tab, 4, j))
	{
		if (check_possible(3, tab, 2, j))
			tab[2][j] = tab[2][j] - 300;
		if (check_possible(3, tab, 3, j))
			tab[3][j] = tab[3][j] - 300;
	}
	else
		return (0);
}

int	test_2_3(int tab[6][6], int type, int i, int j)
{
	if (type == 1)
	{
		if (tab[i][2] != 4000)
			return (0);
		if (check_possible(3, tab, i, 4))
			tab[i][4] = tab[i][4] - 300;
		if (check_possible(1, tab, i, 3))
			tab[i][3] = tab[i][3] - 1;
	}
	else
	{
		if (tab[2][j] != 4000)
			return (0);
		if (check_possible(3, tab, 4, j))
			tab[4][j] = tab[4][j] - 300;
		if (check_possible(1, tab, 3, j))
			tab[3][j] = tab[3][j] - 1;
	}
}

int	test_3_2(int tab[6][6], int type, int i, int j)
{
	if (type == 1)
	{
		if (tab[i][3] != 4000)
			return (0);
		if (check_possible(3, tab, i, 1))
			tab[i][1] = tab[i][1] - 300;
		if (check_possible(1, tab, i, 2))
			tab[i][2] = tab[i][2] - 1;
	}
	else
	{
		if (tab[3][j] != 4000)
			return (0);
		if (check_possible(3, tab, 1, j))
			tab[1][j] = tab[1][j] - 300;
		if (check_possible(1, tab, 2, j))
			tab[2][j] = tab[2][j] - 1;
	}
}
