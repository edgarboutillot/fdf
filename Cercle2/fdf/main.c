/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:45:43 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/19 14:45:43 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	fdf	*data;

	data = (fdf*)malloc(sizeof(fdf));
	if (!data)
		return (NULL);
	read_file(data);
}
