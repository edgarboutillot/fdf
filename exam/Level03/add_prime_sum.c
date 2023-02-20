
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int n)
{
    unsigned int nb;

    nb = n;
    if (n < 0)
    {
        nb = -n;
        ft_putchar('-');
    }
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + '0');
}

int ft_atoi(char *str)
{
    int result;
    int i;

    result = 0;
    i = 0;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    return (result);
}

int is_prime(int n)
{
    int i;

    i = 2;
    while (i < n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int    add_prime_sum(int n)
{
    int sum;
    int i;

    i = 2;
    sum = 0;
    if (n <= 0)
        return (0);
    while (i <= n)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    return (sum);
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac == 2)
    {
        i = ft_atoi(av[1]);
        ft_putnbr(add_prime_sum(i));
    }
    write(1, "\n", 1);
    return (0);
}
