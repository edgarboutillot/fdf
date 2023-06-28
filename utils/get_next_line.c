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

#include "../includes/fdf.h"
#define BUFFER_SIZE 64

/**
 * @brief Find index of the first new line encounter
 * @param str The string where to find a new line
 * @return The position of the first new line encounter in the string.
 * If doesn't find a new line return -1
 */
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

/**
 * @brief Concatenate all the new char to read with the previous ones
 * @param s1 First string to concatenate
 * @param s2 Second string to concatenate
 * @param flag To know if I need to free the malloc or not
 * @return A dynamically allocated variable with the concatenation result
 */
static char	*ft_strjoin_gnl(char *s1, char *s2, int flag)
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

/**
 * @brief return the GNL line and store the extra char
 * @param stock Variable to store all the char that I read
 * @param extra Variable to store all the extra if too much char
 * 				read after the '\n'
 * @return Dynamically allocated variable with the line read
 */
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
	stock = ft_strjoin_gnl(extra, "", 0);
	if (!stock)
		return (NULL);
	byte_read = 1;
	while (byte_read && ft_find_newline(stock) == -1)
	{
		byte_read = read(fd, read_str, BUFFER_SIZE);
		if (byte_read == -1 || (byte_read == 0 && stock[0] == '\0'))
			return (*extra = '\0', free(stock), NULL);
		read_str[byte_read] = '\0';
		stock = ft_strjoin_gnl(stock, read_str, 1);
		if (!stock)
			return (NULL);
	}
	return (ft_split_newline(stock, extra));
}
