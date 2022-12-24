/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:39:22 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/08 12:00:29 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_hexa(long unsigned int i, void *addr, int size)
{
	i = 0;
	while (addr[i] != '\0')
	{
		write (1, &addr[i], 1)
	}
}


void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;

	if (size == 0)
	{
		return ;
	}
	while (i < size)
	{
		ft_put_hexa(i, *addr, size);
	}
	
	return (addr);
}

int	main(void)
{
	char *str = "Bonjour les amin";

	ft_print_memory(str, 17);

	return (0);
}
