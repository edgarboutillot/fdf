
#include <unistd.h>

void    putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int	main(int ac, char **av)
{
    int i;
    int j;

    j = 0;
    i = 0;
    if (ac == 3)
    {
        while (av[2][j])
        {
            if (av[1][i] == av[2][j])
                i++;
            j++;
        }
        if (av[1][i] == '\0')
            putstr(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}
