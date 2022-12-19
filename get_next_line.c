/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:31:40 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/19 18:02:07 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	1. Creer 1 var

*/

int	find_newline(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->buff[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			buff[BUFFER_SIZE + 1];
	int				byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (find_newline(buff) && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
			return (NULL);
		buff[byte] = '\0';
		ft_lstadd_back(&list, buff);
	}
}
