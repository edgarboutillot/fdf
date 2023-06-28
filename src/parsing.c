
#include "../includes/fdf.h"

static t_list	*read_file(char *filename);
t_exit			init_matrix(t_data *data, t_list *matrix);
static t_exit	parse_matrix(t_data *data, t_list *matrix);
static t_exit	parse_line(int width, int *tab, char *line);

t_exit	parsing(t_data *data, int argc, char **argv)
{
	t_list	*matrix;									0

	if (argc != 2)
		return (error_msg("Usage: ./fdf MAPFILE"));
	if (ft_strendwith(argv[1], ".fdf") == FALSE)
		return (error_msg("Extension does not match to `.fdf`"));
	matrix = read_file(argv[1]);
	if (!matrix)
		return (ERROR);
	if (init_matrix(data, matrix) == ERROR)
		return (ERROR);
	if (parse_matrix(data, matrix) == ERROR)
		return (free_array((void **)data->matrix), ft_lstclear(matrix), ERROR);
	return (ft_lstclear(matrix), SUCCESS);
}

static t_list	*read_file(char *filename)
{
	int		fd;
	char	*line;
	t_list	*lst;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_msg(strerror(errno)), NULL);
	lst = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&lst, line);
	}
	close(fd);
	return (lst);
}

static t_exit	parse_matrix(t_data *data, t_list *matrix)
{
	int		i;

	i = 0;
	while (matrix)
	{
		if (parse_line(data->width, data->matrix[i], matrix->line) == ERROR)
			return (ERROR);
		i++;
		matrix = matrix->next;
	}
	return (SUCCESS);
}

static t_exit	parse_line(int width, int *tab, char *line)
{
	char	**res_split;
	int		i;

	res_split = ft_split(line, ' ');
	if (!res_split)
		return (ERROR);
	i = 0;
	while (i < width)
	{
		tab[i] = ft_atoi(res_split[i]);
		i++;
	}
	free_array((void **)res_split);
	return (SUCCESS);
}
