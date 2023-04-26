/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:03:08 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/21 22:18:49 by gmarteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strndup(char *src, int size)
{
	char	*tab;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
