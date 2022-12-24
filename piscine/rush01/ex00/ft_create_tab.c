/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:44:38 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/13 19:11:32 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_create_tab2(int **tab);

int	**ft_create_tab(char *argv, int tab[6][6])
{
	tab[0][0] = 0;
	tab[0][5] = 0;
	tab[5][0] = 0;
	tab[5][5] = 0;
	tab[0][1] = argv[0] - 48;
	tab[0][2] = argv[2] - 48;
	tab[0][3] = argv[4] - 48;
	tab[0][4] = argv[6] - 48;
	tab[5][1] = argv[8] - 48;
	tab[5][2] = argv[10] - 48;
	tab[5][3] = argv[12] - 48;
	tab[5][4] = argv[14] - 48;
	tab[1][0] = argv[16] - 48;
	tab[2][0] = argv[18] - 48;
	tab[3][0] = argv[20] - 48;
	tab[4][0] = argv[22] - 48;
	tab[1][5] = argv[24] - 48;
	tab[2][5] = argv[26] - 48;
	tab[3][5] = argv[28] - 48;
	tab[4][5] = argv[30] - 48;
	ft_create_tab2(tab);
}

void	ft_create_tab2(int tab[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			tab[i][j] = 4321;
			j++;
		}
		i++;
	}
}
