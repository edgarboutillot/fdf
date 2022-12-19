/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:31:44 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/19 17:48:46 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

// secure valeur min && max (=  10000000)

char	*get_next_line(int fd);

// LST
typedef struct s_list	t_list;

struct s_list
{
	char	*buff;
	t_list	*next;
};

t_list	*ft_lstnew(char *buff);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
