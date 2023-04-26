/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:07:14 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/26 13:07:14 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	str_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+' || s1[i] == '-')
		i++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
