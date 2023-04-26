/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:59:20 by gmarteli          #+#    #+#             */
/*   Updated: 2022/08/21 21:17:45 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (is_digit(str[i]))
		i++;
	return (str[i] == '\0');
}

int	is_printable(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 65 && str[i] <= 90) && (str[i] >= 97 && str[i] <= 122))
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	is_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_check_args(int argc, char **argv, char **path, char **value)
{
	if (argc == 2)
	{
		*path = "numbers.dict";
		*value = argv[1];
	}
	else if (argc == 3)
	{
		*path = argv[1];
		*value = argv[2];
	}
	else
		return (0);
	return (1);
}
