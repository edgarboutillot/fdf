
#include <unistd.h>

void   ft_lower(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;
  
    if (ac > 1)
    {
        while (i < ac)
        {
            j = 0;
            ft_lower(av[i]);
            while (av[i][j])
            {
               if ((av[i][j] >= 'a' && av[i][j] <= 'z') && (av[i][j + 1] == ' ' || av[i][j + 1] == '\t' || av[i][j + 1] == '\0'))
                    av[i][j] -= 32;
                write(1, &av[i][j], 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}

