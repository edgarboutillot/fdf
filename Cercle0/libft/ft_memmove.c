/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:15:40 by edboutil          #+#    #+#             */
/*   Updated: 2022/11/25 14:10:33 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
** 	LIBRARY: <string.h>
** 	SYNOPSIS: copy byte string
**
** 	DESCRIPTION:
** 	The memmove() function copies len bytes from string src to string dst.
**  The two strings may overlap; the copy is always done in a
**  non-destructive manner.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src1;
	char	*dst1;

	src1 = (char *)src;
	dst1 = (char *)dst;
	i = 0;
	if (!src1 || !dst1)
		return (NULL);
	if (src1 > dst1)
	{
		ft_memcpy(dst, src, len);
	}
	else if (dst1 > src1)
		while (len-- > 0)
			dst1[len] = src1[len];
	return (dst);
}
