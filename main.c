/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:57:08 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/26 12:57:08 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	init_data(t_data *data);
void	set_hook(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (parsing(&data, argc, argv) == ERROR)
		return (ERROR);
	init_data(&data);
	set_hook(&data);
	mlx_loop(data.mlx_ptr);
}
