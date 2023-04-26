
#include <unistd.h>

int    return_index(char *str, int index)
{
    int i = 0;
    while (str[i] && str[i] == ' ')
    {
        i++;
        index++;
    }
    return (index);
}

int main(int ac, char **av)
{
    int i = 0;
    int index;
    if (ac > 1)
    {
        index = return_index(av[1], i);
        while (av[1][i] && av[1][i] == ' ')
            i++;
        while (av[1][i] && av[1][i] != ' ')
            i++;
        while (av[1][i])
        {
            if (av[1][i] > 32 && av[1][i] < 127)
            {
                write(1, &av[1][i], 1);
            }
            if (av[1][i] == ' ' && (av[1][i + 1] > 32 && av[1][i + 1] < 127))
            {
                write(1, " ", 1);
            }
            i++;
        }
        write(1, " ", 1);
        while (av[1][index] && av[1][index] != ' ')
        {
            write(1, &av[1][index], 1);
            index++;
        }
    }
    write(1, "\n", 1);
    return (0);
}