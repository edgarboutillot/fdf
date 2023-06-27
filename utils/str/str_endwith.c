/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_endwith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:12:58 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/26 20:33:07 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_bool	ft_strendwith(char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;
	int	diff;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	diff = len_s1 - len_s2;
	if (len_s1 >= len_s2 && ft_strcmp(s1 + diff, s2) == 0)
		return (TRUE);
	return (FALSE);
}
