
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src + 1);
	str = malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
