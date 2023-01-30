/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:42:37 by edboutil          #+#    #+#             */
/*   Updated: 2023/01/26 16:13:57 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(str) - 1;
	i = 0;
	printf("%d\n", len);
	while (i < len)
	{
		printf("%c\n", str[i]);
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	//str[i] = '\0';
	return (str);
}



int	main(void)
{
	char test[] = "hello";
	printf("%s\n", ft_strrev(test));
	return (0);
}
