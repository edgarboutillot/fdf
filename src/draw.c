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

static void	print_background(t_data *data);
static void	draw(t_data *data);
static void	bresenham(t_data *data, t_fcoord p1, t_fcoord p2);
static void	handle_transformation(t_data *data, t_fcoord *p1, \
				t_fcoord *p2, t_coord z);

void	render(t_data *data)
{
	print_background(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}

static void	print_background(t_data *data)
{
	t_coord	i;

	i.x = 0;
	while (i.x < WIN_SIZE)
	{
		i.y = 0;
		while (i.y < WIN_SIZE)
		{
			mlx_pixel_put_img(&data->img, i, 0xFFFAD7);
			i.y++;
		}
		i.x++;
	}
}

static void	draw(t_data *data)
{
	t_coord	i;

	i.y = 0;
	while (i.y < data->height)
	{
		i.x = 0;
		while (i.x < data->width)
		{
			if (i.x < data->width - 1)
				bresenham(data, (t_fcoord){i.x, i.y}, (t_fcoord){i.x + 1, i.y});
			if (i.y < data->height - 1)
				bresenham(data, (t_fcoord){i.x, i.y}, (t_fcoord){i.x, i.y + 1});
			i.x++;
		}
		i.y++;
	}
}

static void	bresenham(t_data *data, t_fcoord p1, t_fcoord p2)
{
	t_fcoord	step;
	float		max;
	t_coord		z;

	z.x = data->matrix[(int)p1.y][(int)p1.x];
	z.y = data->matrix[(int)p2.y][(int)p2.x];
	handle_transformation(data, &p1, &p2, z);
	step.x = p2.x - p1.x;
	step.y = p2.y - p1.y;
	max = ft_fmax(ft_fabs(step.x), ft_fabs(step.y));
	step.x /= max;
	step.y /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		mlx_pixel_put_img(&data->img, (t_coord){p1.x, p1.y}, get_color(z.x));
		p1.x += step.x;
		p1.y += step.y;
	}
}

static void	handle_transformation(t_data *data, t_fcoord *p1,
				t_fcoord *p2, t_coord z)
{
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p2->x *= data->zoom;
	p2->y *= data->zoom;
	isometric(p1, z.x);
	isometric(p2, z.y);
	p1->x += data->offset.x;
	p2->x += data->offset.x;
	p1->y += data->offset.y;
	p2->y += data->offset.y;
}
