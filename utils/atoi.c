
#include "../includes/fdf.h"

int	ft_atoi(const char *str)
{
	int						i;
	long long unsigned int	result;
	int						sign;

	i = 0;
	result = 0;
	sign = 1;
	while (((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - 48);
		if (result > __LONG_LONG_MAX__)
			return (0 - (sign == 1));
	}
	return ((int)result * sign);
}
