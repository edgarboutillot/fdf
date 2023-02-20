//
// Created by Edgar Boutillot on 15/02/2023.
//

typedef struct s_list t_list;

struct s_list
{
    int     data;
    t_list  *next;
};

int cmp(int a, int b)
{
    if (a <= b)
        return (1);
    else
        return (0);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *tmp;
    int swap;

    swap = 0;
    tmp = lst;

    while (lst->next != 0)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return (lst);
}

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    t_list *lst;

    lst = malloc(sizeof(t_list));
    lst->data = 20;
    lst->next = malloc(sizeof(t_list));
    lst->next->data = 10;
    lst->next->next = malloc(sizeof(t_list));
    lst->next->next->data = 0;

    lst = sort_list(lst, cmp);

    while (lst != NULL)
    {
        printf("%d\n", lst->data);
        lst = lst->next;
    }
    return (0);
}