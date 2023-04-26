/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:19:56 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/21 22:29:43 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_convert_line(t_dict dict, char *str)
{
	int	i;

	i = 0;
	while (is_digit(str[i]))
		i++;
	if (i == 0)
		return (0);
	dict.key = ft_strndup(str, i);
	str += i;
	while (is_space(str))
	{
		str++;
	}	
	if (*str != ':')
		return (0);
	str++;
	while (is_space(str))
		str++;
	i = 0;
	while (is_printable(str))
		i++;
	if (i == 0 && str[i] != '\n')
		return (0);
	dict.value = ft_strndup(str, i);
	return (1);
}

void	ft_size(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			len++;
		}
		i++;
	}
}

t_dict	*ft_create_tab(char *str)
{	
	int		len;
	int		i;
	t_dict	*dict;

	len = 0;
	i = 0;
	ft_size(str);
	i = 0;
	dict = malloc(sizeof(t_dict) * (len + 1));
	while (*str)
	{
		if (*str == '\n')
			str++;
		if (ft_convert_line(dict[i], str))
		{
			i++;
			while (*str != '\n')
				str++;
		}
		else
			write(1, "Dict Error\n", 11);
	}
	dict[i].key = 0;
	return (dict);
}
