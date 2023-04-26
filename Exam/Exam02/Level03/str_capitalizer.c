
#include <unistd.h>

void    str_capitalizer(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    i = 0;
    while (str[i])
    {
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        if ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
        {
             str[i + 1] -= 32;
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i = 1;
    if (ac > 1)
    {
        while (i < ac)
        {
            str_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}