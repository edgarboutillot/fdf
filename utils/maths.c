/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:02:25 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/27 00:02:28 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_fmax(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

float	ft_fabs(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	isometric(t_fcoord *c, int z)
{
	c->x = (c->x - c->y) * cos(0.8);
	c->y = (c->x + c->y) * sin(0.8) - z;
}
