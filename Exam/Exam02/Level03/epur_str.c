
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i;

        i = 0;
        if (av[1][i] == '\0')
        {
            write(1, "\n", 1);
            return (0);
        }
        while (av[1][i] <= 32 || av[1][i] == 127)
            i++;
        while (av[1][i])
        {
            while (av[1][i] > 32 && av[1][i] < 127)
            {
                write(1, &av[1][i], 1);
                i++;
            }
            while (av[1][i] == ' ')
                i++;
            if (av[1][i] != '\0')
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}