
int is_base(char c, int base)
{
    char *str1 = "0123456789abcdef";
    char *str2 = "0123456789ABCDEF";
    int  i = 0;

    while (base--)
    {
        if (c == str1[base] || c == str2[base])
            return (1);
    }
    return (0);
}

int		ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '-')
    {
        sign = -sign;
        i++;
    }
    while (is_base(str[i], str_base))
    {
        result *= str_base;
        result += ft_value_of(str[i]);
        i++;
    }
    return (result * sign);
}