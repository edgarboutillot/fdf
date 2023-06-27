/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:22:07 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/26 23:22:11 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	hook_mouse_press(int button, int x, int y, t_data *data);
int	hook_key_press(int key, t_data *data);
int	hook_key_release(int key, t_data *data);

int	hook_loop(t_data *data)
{
	if (data->key_press[UP])
		data->offset.y += MOVE_SPEED;
	if (data->key_press[DOWN])
		data->offset.y -= MOVE_SPEED;
	if (data->key_press[LEFT])
		data->offset.x += MOVE_SPEED;
	if (data->key_press[RIGHT])
		data->offset.x -= MOVE_SPEED;
	if (data->key_press[UP] || data->key_press[DOWN] || \
		data->key_press[LEFT] || data->key_press[RIGHT])
		render(data);
	return (SUCCESS);
}

void	set_hook(t_data *data)
{
	mlx_hook(data->win_ptr, 2, (1L << 0), hook_key_press, data);
	mlx_hook(data->win_ptr, 3, (1L << 1), hook_key_release, data);
	mlx_hook(data->win_ptr, 4, (1L << 2), hook_mouse_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_mlx, data);
	mlx_loop_hook(data->mlx_ptr, hook_loop, data);
}
