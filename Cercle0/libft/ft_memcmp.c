/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:00:50 by edboutil          #+#    #+#             */
/*   Updated: 2022/11/25 13:54:45 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
** 	LIBRARY: <string.h>
** 	SYNOPSIS: compare byte string
**
** 	DESCRIPTION:
** 	The memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to be n bytes long.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ss1 != *ss2)
		{
			if (*ss1 < *ss2)
				return (-1);
			else
				return (1);
		}
		ss1++;
		ss2++;
	}
	return (0);
}
