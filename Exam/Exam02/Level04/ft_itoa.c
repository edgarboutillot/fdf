
#include <stdlib.h>

long    nbr_len(long n)
{
    int i;

    i = 0;
    if (n < 0)
    {
        i++;
        n *= -1;
    }
    while (n > 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char	*ft_itoa(int nbr)
{
    char *str;
    long n = nbr;
    int len = nbr_len(nbr);

    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len--] = '\0';
    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    if (n == 0)
    {
        str[0] = '0';
        return (str);
    }
    while (n > 0)
    {
        str[len] = n % 10 + '0';
        n /= 10;
        len--;
    }
    return (str);
}