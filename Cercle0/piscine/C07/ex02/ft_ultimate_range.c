/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:27:44 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/23 15:17:20 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min + 1));
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	(*range)[i] = 0;
	return (i);
}
