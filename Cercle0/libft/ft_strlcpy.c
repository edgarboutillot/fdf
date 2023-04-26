/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:46:18 by edboutil          #+#    #+#             */
/*   Updated: 2022/11/22 12:27:19 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
** 	LIBRARY: <string.h>
** 	SYNOPSIS: size-bounded string copying and concatenation
**
** 	DESCRIPTION:
** 	The strlcpy() and strlcat() functions copy and concatenate strings with the
**	same input parameters and output result as snprintf(3). They are designed to
**	be safer, more consistent, and less error prone replacements for the easily
**	misused functions strncpy(3) and strncat(3).
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}
