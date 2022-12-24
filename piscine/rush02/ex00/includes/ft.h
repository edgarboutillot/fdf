/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:44:34 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/21 22:22:05 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct dict
{
	char	*key;
	char	*value;

}	t_dict;

void	ft_size(char *str);
char	*ft_read_file(char *str);
int		check_number(char *str);
t_dict	*ft_create_tab(char *str);
int		ft_convert_line(t_dict dict, char *str);
int		is_digit(char c);
int		is_printable(char *str);
int		is_space(char *str);
char	*ft_strndup(char *src, int size);
int		ft_check_args(int argc, char **argv, char **path, char **value);
void	ft_print(t_dict *dict);

#endif
