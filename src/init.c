
#include "../includes/fdf.h"

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_SIZE, WIN_SIZE, "FDF");
	data->zoom = 20;
	data->offset.x = WIN_SIZE / 2 - data->width / 2 - 50;
	data->offset.y = WIN_SIZE / 2 - data->height / 2 - 100;
	data->key_press[UP] = FALSE;
	data->key_press[DOWN] = FALSE;
	data->key_press[RIGHT] = FALSE;
	data->key_press[LEFT] = FALSE;
}

t_exit	init_matrix(t_data *data, t_list *matrix)
{
	int	i;

	data->height = ft_lst_size(matrix);
	data->width = count_words(matrix->line, ' ');
	data->matrix = malloc(sizeof(int *) * (data->height));
	if (!data->matrix)
		return (ERROR);
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = malloc(sizeof(int) * (data->width));
		if (!data->matrix[i])
			return (free_n_array((void **)data->matrix, i));
		i++;
	}
	return (SUCCESS);
}

int	close_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_n_array((void **)data->matrix, data->height);
	exit(SUCCESS);
}
