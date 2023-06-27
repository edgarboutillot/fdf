/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:58:32 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/26 12:58:32 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham(float x1, float y1, float x2, float y2, t_data *data)
{
	float   x_step;
	float   y_step;
	int     max;
	int     z1;
	int     z2;

	z1 = data->matrix[(int)y1][(int)x1];
	z2 = data->matrix[(int)y2][(int)x2];

	//--------------------Zoom--------------
	x1 *= data->zoom;
	y1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	//--------------------Color--------------

	data->color = (z1 || z2) ? 0xe80c0c : 0xffffff;

	//------------------3D------------------
	isometric(&x1, &y1, z1);
	isometric(&x2, &y2, z2);

	x1 += data->offset.x;
	x2 += data->offset.x;
	y1 += data->offset.y;
	y2 += data->offset.y;

	x_step = x2 - x1;
	y_step = y2 - y1;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
		x1 += x_step;
		y1 += y_step;
	}
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
