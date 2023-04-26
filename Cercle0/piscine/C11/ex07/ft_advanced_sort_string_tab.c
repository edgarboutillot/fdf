/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:39:40 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/25 18:44:19 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (tab[size] != 0)
	{
		size++;
	}
	while (i < size - 1)
	{
		if ((*cmp)(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
