/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:14:51 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/27 21:14:59 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	hook_mouse_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if ((button == SCROLL_IN && data->zoom < 1000) || \
		(button == SCROLL_OUT))// && data->zoom > 10))
	{
		if (button == SCROLL_IN)
			data->zoom *= 1.5;
		else
			data->zoom /= 1.5;
		printf("%d\n", data->zoom);
		render(data);
	}
	return (SUCCESS);
}
