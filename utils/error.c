/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:24:48 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/26 20:24:48 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_putstr_fd(char const *s, int fd);

t_exit	error_msg(char *msg)
{
	ft_putstr_fd("fdf: ", STDERR);
	ft_putstr_fd(msg, STDERR);
	ft_putstr_fd("\n", STDERR);
	return (ERROR);
}

static void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s && s[i])
		write(fd, &s[i++], 1);
}
