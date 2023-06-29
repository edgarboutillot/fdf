/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:14:59 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/27 19:59:56 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_SIZE, WIN_SIZE, "FDF");
	data->img.img = mlx_new_image(data->mlx_ptr, WIN_SIZE, WIN_SIZE);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->\
		img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	data->key_press[UP] = FALSE;
	data->key_press[DOWN] = FALSE;
	data->key_press[RIGHT] = FALSE;
	data->key_press[LEFT] = FALSE;
	data->size_diff = 100.0 / (data->max - data->min + 1);
	printf("%f\n", data->size_diff);
	set_default_value(data);
}

t_exit	init_matrix(t_data *data, t_list *matrix)
{
	int	i;

	data->height = ft_lst_size(matrix);
	data->width = count_words(matrix->line, ' ');
	data->matrix = malloc(sizeof(int *) * (data->height));
	if (!data->matrix)
		return (ERROR);
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = malloc(sizeof(int) * (data->width));
		if (!data->matrix[i])
			return (free_n_array((void **)data->matrix, i));
		i++;
	}
	return (SUCCESS);
}

void	set_default_value(t_data *data)
{
	data->zoom = ft_max(data->width, data->height) * 35 / 19;
//	data->zoom = (data->width * data->height) / 125000;
	data->offset.x = WIN_SIZE / 2 - data->width / 2 - (data->width * 90 / 19);
	data->offset.y = WIN_SIZE / 2 - data->height / 2 - (data->height * 180 / 11);
	printf("%d - %d\n", data->height, data->width);
	printf("%d\n", data->zoom);
	render(data);
}
