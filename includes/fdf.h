/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:59:36 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/27 20:42:44 by edboutil         ###   ########.fr       */
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

# define MOVE_SPEED		10
# define WIN_SIZE	    1000

// TYPEDEF ------------------------------------------------
typedef struct s_img	t_img;
typedef struct s_data	t_data;
typedef struct s_coord	t_coord;
typedef struct s_fcoord	t_fcoord;
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
	Q = 12,
	W = 13,
	ESQ = 53,
	LEFT_KEY = 123,
	RIGHT_KEY = 124,
	DOWN_KEY = 125,
	UP_KEY = 126,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
};

# endif

# ifdef __linux__

enum e_keycode
{
	A = 97,
	S = 115,
	D = 100,
	W = 119,
	Q = 113,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	DOWN_KEY = 65364,
	UP_KEY = 65362,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
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
struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_coord
{
	int	x;
	int	y;
};

struct s_fcoord
{
	float	x;
	float	y;
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
	t_coord	offset;
	void	*mlx_ptr;
	void	*win_ptr;
	int		min;
	int		max;
	double	size_diff;
	t_img	img;
	t_bool	key_press[4];
};

// PARSING ------------------------------------------------
t_exit	parsing(t_data *data, int argc, char **argv);
t_exit	parse_line_julia(int width, int *tab, char *line);

// GRAPH --------------------------------------------------
void	render(t_data *data);
void	isometric(t_fcoord *c, int z);
void	set_default_value(t_data *data);
int		get_color(int altitude);

// UTILS --------------------------------------------------
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

void	mlx_pixel_put_img(t_img *img, t_coord c, int color);
int		close_mlx(t_data *data);

float	ft_fmax(float x, float y);
int		ft_max(int x, int y);
float	ft_fabs(float i);
int		ft_abs(int i);

#include <stdio.h>

#endif
