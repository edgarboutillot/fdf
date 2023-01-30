/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:40:43 by edboutil          #+#    #+#             */
/*   Updated: 2023/01/26 15:35:05 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s1)
	{
		j = 0;
		while (s2[j])
		{
			if (*s1 == s2[j])
			{
				return ((char *)s1);
			}
			j++;
		}
		s1++;
	}
	return (0);
}


#include <stdio.h>
#include <string.h>

int	main(void)
{
	char test[] = "check";
	char test1[] = "e";

	printf("%s\n", strpbrk(test, test1));
	printf("%s\n", ft_strpbrk(test, test1));
	return (0);
}
