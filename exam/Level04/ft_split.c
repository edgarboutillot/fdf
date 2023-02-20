
#include <stdlib.h>

int word_len(char *str, int i)
{
    int count = 0;
    while (str[i] && str[i] != ' ')
    {
        i++;
        count++;
    }
    return (count);
}

int count_words(char *str)
{
    int i;
    int count = 0;

    i = 0;
    while (str[i])
    {
        while (str[i] && str[i] == ' ')
        {
            i++;
        }
        if (str[i] && str[i] != ' ')
        {
            while (str[i] && str[i] != ' ')
            {
                i++;
            }
            count++;
        }
    }
    return (count);
}

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k;
    char **tab;

    tab = malloc(sizeof(char*) * count_words(str) + 1);
    if (!tab)
        return (NULL);
    while (str[i])
    {
        while (str[i] && str[i] == ' ')
            i++;
        if (str[i])
        {
            k = 0;
            tab[j] = malloc(sizeof(char) * word_len(str, i) + 1);
            if (!tab)
                return (NULL);
            while (str[i] && str[i] != ' ')
            {
                tab[j][k++] = str[i++];
            }
            tab[j][k] = '\0';
            j++;
        }
    }
    tab[j] = NULL;
    return (tab);
}