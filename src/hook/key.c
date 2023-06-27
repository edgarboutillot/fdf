/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:14:46 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/27 21:15:23 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	hook_key_press(int key, t_data *data)
{
	ft_printf("%d\n", key);
	if (key == W || key == UP_KEY)
		data->key_press[UP] = TRUE;
	else if (key == S || key == DOWN_KEY)
		data->key_press[DOWN] = TRUE;
	else if (key == A || key == LEFT_KEY)
		data->key_press[LEFT] = TRUE;
	else if (key == D || key == RIGHT_KEY)
		data->key_press[RIGHT] = TRUE;
	else if (key == Q)
		set_default_value(data);
	else if (key == ESQ)
		close_mlx(data);
	return (SUCCESS);
}

int	hook_key_release(int key, t_data *data)
{
	if (key == W || key == UP_KEY)
		data->key_press[UP] = FALSE;
	else if (key == S || key == DOWN_KEY)
		data->key_press[DOWN] = FALSE;
	else if (key == A || key == LEFT_KEY)
		data->key_press[LEFT] = FALSE;
	else if (key == D || key == RIGHT_KEY)
		data->key_press[RIGHT] = FALSE;
	return (SUCCESS);
}
