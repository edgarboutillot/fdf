/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:45:18 by edboutil          #+#    #+#             */
/*   Updated: 2022/11/25 13:09:50 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;
	unsigned int	len_s;

	len_s = ft_strlen(s);
	if (start > len_s)
		len = 0;
	else if (len > len_s - start)
		len = len_s - start;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
