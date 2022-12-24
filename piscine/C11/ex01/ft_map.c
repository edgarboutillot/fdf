/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:05:36 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/25 10:58:04 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*flo;
	int	i;

	i = 0;
	flo = malloc(sizeof(int) * (length));
	if (tab == NULL)
		return (NULL);
	while (i < length)
	{
		flo[i] = f(tab[i]);
		i++;
	}
	return (flo);
}
