/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:07:51 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/27 20:07:57 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_pixel_put_img(t_img *img, t_coord c, int color)
{
	char	*dst;

	if (c.x < 0 || c.x >= WIN_SIZE || c.y < 0 || c.y >= WIN_SIZE)
		return ;
	dst = img->addr + (c.y * img->line_length + c.x * \
		(img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_n_array((void **)data->matrix, data->height);
	exit(SUCCESS);
}

