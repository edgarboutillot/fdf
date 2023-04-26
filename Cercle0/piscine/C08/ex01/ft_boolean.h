/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:29:43 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/23 18:39:27 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef char	t_bool;

# define TRUE 1
# define FALSE 0
# define EVEN(nbr) (nbr % 2 == 0)
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0

#endif
