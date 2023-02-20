
#include <unistd.h>

void    ft_putnbr(int nb)
{
    char *hex = "0123456789abcedf";

    if (nb >= 16)
        ft_putnbr(nb / 16);
    write(1, &hex[nb % 16], 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result *= 10;
        result += str[i] - '0';
        i++;
    }
    return (result);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = ft_atoi(av[1]);
        ft_putnbr(i);
    }
    write(1, "\n", 1);
    return (0);
}