/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:58:46 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/26 12:58:46 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int get_height(char *file_name)
{
	char *line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_putstr_fd("Failed to open file\n", 2);
		exit(0);
	}
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("Failed to close file\n", 2);
		return (-1);
	}
	return (height);
}

int get_width(char *file_name)
{
	char *line;
	int fd;
	int width;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_putstr_fd("Failed to open file\n", 2);
		exit(0);
	}
	get_next_line(fd, &line);
	width = ft_words_counter(line, ' ');
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Failed to close file\n", 2);
		return (-1);
	}
	return (width);
}

void    fill_matrix(int *z_line, char *line)
{
	char **tab;
	int     i;

	i = 0;
	tab = ft_split(line, ' ');
	while (tab[i])
	{
		z_line[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	read_file(char *file_name, fdf *data)
{
	char *line;
	int 	fd;
	int 	i;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	while (i <= data->height)
		data->matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->matrix[i] = NULL;
}