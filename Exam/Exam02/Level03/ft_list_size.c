
#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int     ft_list_size(t_list *begin_list)
{
    int i;

    i = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}

t_list  *new_element(void   *data)
{
    t_list *element;

    element = malloc(sizeof(t_list));
    if (element)
    {
        element->data = data;
        element->next = NULL;
    }
    return (element);
}

int main()
{
    t_list *p0, *p1, *p2, *p3;

    p0 = new_element("Beubeu");
    p1 = new_element("Florian");
    p2 = new_element("Bilou");
    p3 = new_element("Jojo");

    p0->next = p1;
    p1->next = p2;
    p2->next = p3;

    printf("%d\n", ft_list_size(p0));
    return (0);
}