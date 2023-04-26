
#include <stdlib.h>
#include <stdio.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

int cmp(int *data, int *data_ref)
{
    int *pa = data;
    int *pb = data_ref;
    if (*pa == *pb)
        return (0);
    return (1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *remove;
    t_list *current;

    current = *begin_list;
    while (current && current->next)
    {
        if ((*cmp)(current->next->data, data_ref) == 0)
        {
            remove = current->next;
            current->next = current->next->next;
            free(remove);
        }
        current = current->next;
    }
    current = *begin_list;
    if (current && (*cmp)(current->data, data_ref) == 0)
    {
        *begin_list = current->next;
        free(current);
    }

}

int main(void)
{
    t_list *lst;
    int i = 1;
    int j = 2;

    lst = malloc(sizeof(t_list));
    lst->data = &j;
    lst->next = malloc(sizeof(t_list));
    lst->next->data = &i;
    lst->next->next = malloc(sizeof(t_list));
    lst->next->next->data = &j;
    lst->next->next->next = malloc(sizeof(t_list));
    lst->next->next->next->data = &i;
    lst->next->next->next->next = NULL;

    ft_list_remove_if(&lst, &j, cmp);
    while (lst != NULL)
    {
        printf("%d", *(int*)lst->data);
        lst = lst->next;
    }
    return (0);
}