
#include <stdlib.h>

int ft_abs(int x)
{
    if (x < 0)
        return (-x);
    return (x);
}

int     *ft_range(int start, int end)
{
    int *tab;
    int i = 0;

    tab = malloc(sizeof(int) * ft_abs(start - end) + 1);
    if (!tab)
        return (NULL);
    while (start < end)
    {
        tab[i] = start;
        i++;
        start++;
    }
    tab[i] = start;
    while (start > end)
    {
        tab[i] = start;
        i++;
        start--;
    }
    tab[i] = start;
    return (tab);
}