/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:40:38 by gmarteli          #+#    #+#             */
/*   Updated: 2022/08/21 22:28:51 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read_file(char *path)
{
	int		fd;
	char	*buffer;
	int		i;
	int		rd;

	buffer = malloc(sizeof(char) * 4000);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		write(2, "Dict Error\n", 11);
	return (0);
	rd = (read(fd, buffer + i, 1));
	while (read(fd, buffer + i, 1) == 1)
	{
		i++;
	}
	if (rd == -1)
	{
		write(2, "Dict Error\n", 11);
	}
	close(fd);
	return (buffer);
}
