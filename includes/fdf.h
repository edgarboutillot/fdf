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

#ifndef FDF_H
# define FDF_H

// INCLUDE ------------------------------------------------
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# ifdef __APPLE__
#  include "../mlx/mac/mlx.h"
# endif

# ifdef __linux__
#  include "../mlx/linux/mlx.h"
# endif

# define WIN_SIZE	1000

// TYPEDEF ------------------------------------------------
typedef struct s_arr	t_arr;
typedef struct s_data	t_data;
typedef struct s_coord	t_coord;
typedef struct s_list	t_list;
typedef enum e_exit		t_exit;
typedef enum e_bool		t_bool;

// ENUM ---------------------------------------------------
# ifdef __APPLE__

enum e_keycode
{
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	ESQ = 53,
};
# endif

# ifdef __linux__

enum e_keycode
{
	A = 97,
	S = 115,
	D = 100,
	W = 119,
	ESQ = 65307,
};
# endif

enum e_exit
{
	SUCCESS,
	ERROR,
};

enum e_fd
{
	STDIN,
	STDOUT,
	STDERR,
};

enum e_bool
{
	FALSE,
	TRUE,
};

enum e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

// STRUCT -------------------------------------------------
struct s_coord
{
	int	x;
	int	y;
};

struct s_list
{
	char	*line;
	t_list	*next;
};

struct s_data
{
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	t_coord	offset;
	void	*mlx_ptr;
	void	*win_ptr;
	t_bool	key_press[4];
};

// PARSING ------------------------------------------------
t_exit	parsing(t_data *data, int argc, char **argv);

// GRAPH --------------------------------------------------
void	bresenham(float x1, float y1, float x2, float y2, t_data *data);
void	plot(float x, float y, t_data *data);
void	draw_horizontal(float x1, float x2, float y, t_data *data, float stepX);
void	draw_vertical(float x, float y1, float y2, t_data *data, float stepY);
void	draw(t_data *data);

void	isometric(float *x, float *y, int z);

// UTILS --------------------------------------------------
int		ft_printf(const char *format, ...);
char	**ft_split(char const *str, char c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
t_bool	ft_strendwith(char *s1, char *s2);
int		ft_atoi(const char *str);
t_exit	error_msg(char *msg);
void	ft_lstadd_back(t_list **lst, char *line);
int		ft_lst_size(t_list *top_a);
void	ft_lstclear(t_list *lst);
int		count_words(char const *str, char charset);
t_exit	free_array(void **array);
t_exit	free_n_array(void **array, int size);
int		close_mlx(t_data *data);
int		ft_max(int x, int y);
float	ft_abs(float i);
void	isometric(float *x, float *y, int z);

#endif
