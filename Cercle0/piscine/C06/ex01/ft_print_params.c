/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:57:12 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/12 13:21:16 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 1;
	k = 0;
	while (i < argc)
	{
		k = 0;
		while (argv[j][k] != '\0')
		{
			write(1, &argv[j][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
		j++;
	}
	return (0);
}
