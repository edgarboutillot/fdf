/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:46:46 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/19 14:46:46 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

// INCLUDE ------------------------------------------------
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

// TYPEDEF ------------------------------------------------


// STRUCT -------------------------------------------------
typedef struct	s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;

typedef struct
{
	int width;
	int weight;
	int **z_matrix;

	void *mlx_ptr;
	void *win_ptr;
}		fdf;

// ENUM ---------------------------------------------------


// PARSING ------------------------------------------------


// GRAPH ---------------------------------------------------

// READ_MAP ------------------------------------------------

void	read_file(char *file_name, fdf *data);

// UTILS --------------------------------------------------
int		ft_printf(const char *format, ...);
char	**ft_split(const char *str, char c);
int		get_next_line(const int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strcpy(char *dest, char *src);
size_t	ft_strlen(const char *s);
char    *ft_strcat(char *dest, char *src);
char	*ft_strnew(size_t size);
void	ft_strclr(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);

#endif
