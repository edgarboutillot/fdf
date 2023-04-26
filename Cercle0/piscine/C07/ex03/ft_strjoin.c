/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:02 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/24 10:47:20 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	malloc_size(int size, char **strs, char *sep)
{
	int	i;
	int	len;
	int	len_sep;

	len = 1;
	i = 0;
	len_sep = ft_strlen(sep);
	while (i < size)
	{
		if (i + 1 != size)
		{
			len += len_sep;
		}
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * malloc_size(size, strs, sep));
	if (tab == NULL)
		return (NULL);
	tab[0] = '\0';
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i < size - 1)
		{
			ft_strcat(tab, sep);
		}
		i++;
	}
	return (tab);
}
