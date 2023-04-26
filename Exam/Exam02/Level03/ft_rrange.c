
#include <stdlib.h>

int ft_abs(int x)
{
    if (x < 0)
        return (-x);
    return (x);
}

int     *ft_rrange(int start, int end)
{
    int *tab;
    int i;

    i = 0;
    tab = malloc(sizeof(int) * ft_abs(end - start) + 1);
    if (!tab)
        return (NULL);
    while (end < start)
    {
        tab[i] = end;
        end++;
        i++;
    }
    tab[i] = end;
    while (end > start)
    {
        tab[i] = end;
        end--;
        i++;
    }
    tab[i] = end;
    return (tab);
}