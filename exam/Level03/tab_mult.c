
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int n = 0;

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        n *= 10;
        n += str[i] - 48;
        i++;
    }
    return (n);
}

void ft_putnbr(int nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + 48);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(1, "\n", 1);
    }
    else
    {
        int i = 1;
        int number = ft_atoi(av[1]);
        while (i <= 9)
        {
           ft_putnbr(i);
           write(1, " x ", 3);
           ft_putnbr(number);
           write(1, " = ", 3);
           ft_putnbr(i * number);
           write(1, "\n", 1);
           i++;
        }
    }
    return (0);   
}