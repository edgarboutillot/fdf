/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:18:48 by tjan              #+#    #+#             */
/*   Updated: 2022/08/14 14:57:39 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	test_1_2(int tab[6][6], int type, int i, int j);
int	test_2_1(int tab[6][6], int type, int i, int j);
int	test_1_3(int tab[6][6], int type, int i, int j);
int	test_3_1(int tab[6][6], int type, int i, int j);
int	test_2_2(int tab[6][6], int type, int i, int j);
int	test_2_2_bis(int tab[6][6], int type, int i, int j);
int	test_2_3(int tab[6][6], int type, int i, int j);
int	test_3_2(int tab[6][6], int type, int i, int j);
int	check_tab_line(int tab[6][6]);
int	check_tab_col(int tab[6][6]);


int	check_tab(tab[6][6])
{
	int	boolean;

	boolean = check_tab_col(int tab[6][6]);
	if (boolean == 0)
		return (0);
	boolean = check_tab_line(int tab[6][6]);
	return (boolean);
}

int	check_tab_line(int tab[6][6])
{
	int	i;
	int	boolean;

	boolean = 1;
	i = 1;
	while (i < 5 && boolean == 1)
	{
		if (tab[i][0] == 1 && tab[i][5] == 2)
			boolean = test_1_2(tab, 1, i, 1);
		else if (tab[i][0] == 2 && tab[i][5] == 1)
			boolean = test_2_1(tab, 1, i, 1);
		else if (tab[i][0] == 1 && tab[i][5] == 3)
			boolean = test_1_3(tab, 1, i, 1);
		else if (tab[i][0] == 3 && tab[i][5] == 1)
			boolean = test_3_1(tab, 1, i, 1);
		else if (tab[i][0] == 2 && tab[i][5] == 2)
			boolean = test_2_2(tab, 1, i, 1);
		else if (tab[i][0] == 2 && tab[i][5] == 3)
			boolean = test_2_3(tab, 1, i, 1);
		else if (tab[i][0] == 3 && tab[i][5] == 2)
			boolean = test_3_2(tab, 1, i, 1);	
		i++;		
	}
	if (boolean == 0)
		return (0);
	return (1);
}

int	check_tab_col(int tab[6][6])
{
	int	j;
	int	boolean;

	boolean = 1;
	j = 1;
	while (j < 5 && boolean == 1)
	{
		if (tab[0][j] == 1 && tab[5][j] == 2)
			boolean = test_1_2(tab, 0, 1, j);
		else if (tab[0][j] == 2 && tab[5][j] == 1)
			boolean = test_2_1(tab, 0, 1, j);
		else if (tab[0][j] == 1 && tab[5][j] == 3)
			boolean = test_1_3(tab, 0, 1, j);
		else if (tab[0][j] == 3 && tab[5][j] == 1)
			boolean = test_3_1(tab, 0, 1, j);
		else if (tab[0][j] == 2 && tab[5][j] == 2)
			boolean = test_2_2(tab, 0, 1, j);
		else if (tab[0][j] == 2 && tab[5][j] == 3)
			boolean = test_2_3(tab, 0, 1, j);
		else if (tab[0][j] == 3 && tab[5][j] == 2)
			boolean = test_3_2(tab, 0, 1, j);	
		j++;		
	}
	if (boolean == 0)
		return (0);
	return (1);
}


//Savoir si un nombre fait toujours partie des possibilitees
int	check_possible(int nb, int tab[6][6], int i, int j)
{
	if (nb == 4 && tab[i][j] / 1000 == 4)
		return (1);
	else if (nb == 3 && (tab[i][j] % 1000) / 100 == 3)
	   return (1);
	else if (nb == 2 && ((tab[i][j] % 1000) % 100) / 10 == 2)
	   return (1);
	else if (nb == 1 && tab[i][j] % 10 == 1)
	   return (1);
	else
		return (0);
}


// Savoir si on a trouve le nombre final
int	check_nb(int tab[6][6], int i, int j)
{
	if (tab[i][j] == 4000 || tab[i][j] == 300
		|| tab[i][j] == 20 || tab[i][j] == 1)
		return (tab[i][j]);
	else
		return (0);
}

// Verifier si il y a un doublon sur une colonne
int	check_col(int tab[6][6], int j)
{
	int	i;
	int	i_2;

	while (i < 4)
	{
		i_2 = i + 1;
		while (i_2 < 5)
		{
			if (check_nb(tab, i_2, j) && check_nb(tab, i, j) && tab[i][j] == tab[i_2][j])
				return (0);
			i_2++;
		}
		i++;
	}
	return (1);
}

// Verfiier si il y a un doublon sur une ligne
int	check_line(int tab[6][6], int i)
{
	int	j;
	int	j_2;

	while (j < 4)
	{
		j_2 = j + 1;
		while (j_2 < 5)
		{
			if (check_nb(tab, i, j) && check_nb(tab, i, j_2) && tab[i][j] == tab[i][j_2])
				return (0);
			j_2++;
		}
		j++;
	}
	return (1);
}

// Verifier si il n y a aucune solution sur une ligne
int	check_no_solution_line(int tab[6][6], int i)
{
	int	j_2;
	int	test;
	int	boolean;

	test = 1;
	boolean = 0
	while (test <= 4)
	{
		j_2 = 1;
		boolean = 1
		while (j_2 < 5)
		{
			if (check_possible(test, tab, i, j_2))
				boolean++;
			j_2++;
		}
		if (boolean == 0)
			return (0)
		test++;
	}
}

// Verifier si il n y a aucune solution sur une colonne
int	check_no_solution_col(int tab[6][6], int j)
{
	int	i_2;

	test = 1;
	while (test <= 4)
	{
		i_2 = 1;
		boolean = 1
		while (i_2 <= 4)
		{
			if (check_possible(test, tab, i_2, j))
				boolean++;
			i_2++;
		}
		if (boolean == 0)
			return (0);
		test++;
	}
	return (1);
}
