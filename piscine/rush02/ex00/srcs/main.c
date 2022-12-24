/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:43:04 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/21 22:25:31 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	char	*path;
	char	*nbr;
	char	*read;
	t_dict	*dict;

	if (ft_check_args(argc, argv, &path, &nbr) && check_number(nbr))
	{
		read = ft_read_file(path);
		if (*read)
		{
			dict = ft_create_tab(read);
			free(read);
			ft_print(dict);
		}
		else
			write(1, "Dict Error\n", 11);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
