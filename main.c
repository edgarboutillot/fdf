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
#include <stdio.h>

int deal_key(int key, fdf *data)
{
	//(void)data;
	printf("%d\n", key);

	if (key == 119)
		data->shift_y -= 10;
	if (key == 97)
		data->shift_y += 10;
	if (key == 115)
		data->shift_x -= 10;
	if (key == 100)
		data->shift_x += 10;
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf *data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf MAPFILE\n", 2);
		return (-1);
	}
	data = (fdf *)malloc(sizeof(fdf));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	read_file(argv[1], data);
	data->zoom = 20;
	//bresenham(10, 10, 600, 300, data);
	if (data != NULL)
		draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);

	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}