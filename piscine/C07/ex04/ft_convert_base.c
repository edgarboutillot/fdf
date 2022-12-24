/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:29:42 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/23 22:13:54 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	nbr_len(unsigned int nbr, unsigned int b)
{
	int	len;

	len = 0;
	while (nbr >= b)
	{
		nbr /= b;
		len++;
	}
	return (len);
}

int	is_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	i;
	int	sign;
	int	b;

	i = 0;
	result = 0;
	sign = 1;
	b = check_base(base);
	if (b < 1)
		return (0);
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && is_digit(str[i], base) >= 0)
	{
		result = result * b + is_digit(str[i], base);
		i++;
	}
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*final;
	int				nb_atoi;
	int				len_n;
	unsigned int	n;

	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	nb_atoi = ft_atoi_base(nbr, base_from);
	if (nb_atoi < 0)
		n = -nb_atoi;
	else
		n = nb_atoi;
	len_n = nbr_len(n, check_base(base_to)) + 1 + ((nb_atoi < 0));
	final = (char *)malloc(sizeof(char) * (len_n + 1));
	final[len_n] = '\0';
	while (len_n--)
	{
		final[len_n] = base_to[n % check_base(base_to)];
		n /= check_base(base_to);
	}
	if (nb_atoi < 0)
		final[0] = '-';
	return (final);
}
