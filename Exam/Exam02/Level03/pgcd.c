
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac == 3)
    {
        int a = atoi(av[1]);
        int b = atoi(av[2]);
        int max;
        int result = 0;
        if (a <= 0 || b <= 0)
            return (0);
        if (a > b)
            max = b;
        else
            max = a;
        while (i <= max)
        {
            if (a % i == 0 && b % i == 0)
                result = i;
            i++;
        }
        printf("%d", result);
    }
    printf("\n");
    return (0);
}

