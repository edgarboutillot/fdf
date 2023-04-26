/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:12:53 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/23 12:15:14 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

//# if BUFFER_SIZE >= 10000000
//#  define BUFFER_SIZE 20
//# endif

char	*get_next_line(int fd);

#endif
