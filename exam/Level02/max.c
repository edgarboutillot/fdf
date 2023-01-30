/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:21:16 by edboutil          #+#    #+#             */
/*   Updated: 2023/01/26 18:26:49 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int max;

	while (len)
	{
		if (tab[len] > max)
		{
			max = tab[len];
		}
		len--;
	}
	return (max);
}
