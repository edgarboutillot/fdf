
#include <unistd.h>

int	check_double(char c, char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_double2(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check_double(av[1][i], av[1], i))
				write(1, &av[1][i], 1);
			i++;
		}
		i = 0;
		while (av[2][j])
		{
			if (check_double2(av[1], av[2][j]))
			{
				if (check_double(av[2][j], av[2], j))
					write(1, &av[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
}
