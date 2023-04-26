/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:48:41 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/18 19:34:41 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
