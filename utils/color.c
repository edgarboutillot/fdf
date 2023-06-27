/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:30:16 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/27 21:30:18 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define GRADIENT_SIZE	6

int	get_color(int altitude)
{
	const int	colors[GRADIENT_SIZE] = {0x845ec2, 0xd65db1, 0xff6f91, \
		0xff9671, 0xffc75f, 0xf9f871};

	return (colors[ft_abs(altitude) % GRADIENT_SIZE]);
}
