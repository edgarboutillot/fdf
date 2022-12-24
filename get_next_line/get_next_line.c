/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:06:52 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/23 13:47:10 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*tmp;
	int		index_tmp;
	int		index_str;

	tmp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
	{
		if (flag)
			free(s1);
		return (NULL);
	}
	index_tmp = 0;
	index_str = 0;
	while (s1[index_str])
		tmp[index_tmp++] = s1[index_str++];
	index_str = 0;
	while (s2[index_str])
		tmp[index_tmp++] = s2[index_str++];
	tmp[index_tmp] = '\0';
	if (flag)
		free(s1);
	return (tmp);
}

static char	*ft_split_newline(char *stock, char *extra)
{
	int		pos;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	pos = ft_find_newline(stock);
	if (pos == -1)
	{
		*extra = '\0';
		return (stock);
	}
	tmp = malloc(sizeof(char) * (pos + 2));
	if (!tmp)
		return (free(stock), NULL);
	while (i <= pos)
		tmp[i++] = stock[j++];
	tmp[i] = '\0';
	i = 0;
	while (stock[j])
		extra[i++] = stock[j++];
	extra[i] = '\0';
	free(stock);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	extra[BUFFER_SIZE] = "";
	char		read_str[BUFFER_SIZE + 1];
	int			byte_read;
	char		*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_strjoin(extra, "", 0);
	if (!stock)
		return (NULL);
	byte_read = 1;
	while (byte_read && ft_find_newline(stock) == -1)
	{
		byte_read = read(fd, read_str, BUFFER_SIZE);
		if (byte_read == -1 || (byte_read == 0 && stock[0] == '\0'))
			return (*extra = '\0', free(stock), NULL);
		read_str[byte_read] = '\0';
		stock = ft_strjoin(stock, read_str, 1);
		if (!stock)
			return (NULL);
	}
	return (ft_split_newline(stock, extra));
}
