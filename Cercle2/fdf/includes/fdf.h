/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:59:36 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/26 12:59:36 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

// INCLUDE ------------------------------------------------
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx/linux/mlx.h"


//# ifdef __APPLE__
//#  include "../mlx/mac/mlx.h"
//# endif
//
//# ifdef __linux__
//# endif

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
	int height;
	int **matrix;
	int zoom;
	int color;
	int shift_x;
	int shift_y;
	void *mlx_ptr;
	void *win_ptr;
}		fdf;

// ENUM ---------------------------------------------------


// PARSING ------------------------------------------------


// GRAPH ---------------------------------------------------
void 	bresenham(float x1, float y1, float x2, float y2, fdf *data);
void    plot(float x, float y, fdf *data);
void    draw_horizontal(float x1, float x2, float y, fdf *data, float stepX);
void    draw_vertical(float x, float y1, float y2, fdf *data, float stepY);
void    draw(fdf *data);

void	isometric(float *x, float *y, int z);


// READ_MAP ------------------------------------------------
void	read_file(char *file_name, fdf *data);


// UTILS --------------------------------------------------
int		ft_printf(const char *format, ...);
char	**ft_split(char const *str, char c);
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
int 	ft_atoi(const char *str);
int		ft_words_counter(char const *str, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);

#endif


