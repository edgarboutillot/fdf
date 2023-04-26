/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:23:56 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/14 15:01:33 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		**ft_create_tab(char *argv, int tab[6][6]);
int		ft_check_size(char	*tab);
void	ft_print_tab(int tab[6][6]);

int	main(void)
{
	int		tab[6][6];
	char	argv[];

	argv = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	if (ft_check_size(argv) == 0)
	{
		write(1, "Size invalid\n", 13);
		return (0);
	}
	ft_create_tab(argv, tab);

	ft_print_tab(tab);
	return (0);
}
