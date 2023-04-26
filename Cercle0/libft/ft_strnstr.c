/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:32:00 by edboutil          #+#    #+#             */
/*   Updated: 2022/11/22 13:58:54 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
** 	LIBRARY: <string.h>
** 	SYNOPSIS: locate a substring in a string
**
** 	DESCRIPTION:
** 	The strnstr() function locates the first occurrence of the null-terminated
**	string needle in the string haystack, where not more than len characters are
**	searched. Characters that appear after a `\0' character are not searched.
**	Since the strnstr() function is a FreeBSD specific API, it should only be
**	used when portability is not a concern.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0' || haystack == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
