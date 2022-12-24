/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:50:54 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/23 18:51:20 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (char_sep(str[i + 1], charset) == 1
			&& (char_sep(str[i], charset) == 0))
			words++;
		i++;
	}
	return (words);
}

void	strcpy_split(char *copy, char *str, char *charset)
{
	int	i;

	i = 0;
	while (char_sep(str[i], charset) == 0)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
}

void	write_words(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (char_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_sep(str[i + j], charset) == 0)
			{
				j++;
			}
			split[words] = (char *)malloc(sizeof(char) * (j + 1));
			strcpy_split(split[words], str + i, charset);
			i += j;
			words++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		words;

	words = count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	tab[words] = 0;
	write_words(tab, str, charset);
	return (tab);
}
