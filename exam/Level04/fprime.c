
#include <stdio.h>
#include <stdlib.h>

void ft_prime(int nb)
{
    int i;
    int sum;
    
    sum = 0;
    i = 3;
    if (nb == 1)
        printf("1");
    while (nb > 1 && nb % 2 == 0)
    {
        printf("2*");
        nb /= 2;
    }
    while (nb >= i)
    {
        if (nb % i == 0)
        {
            printf("%d", i);
            if (nb != i)
                printf("*");
            nb = nb / i;
        }
        else
            i += 2;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nb = atoi(av[1]);
        ft_prime(nb);
        printf("\n");
    }
    else
        printf("\n");
    return (0);
}