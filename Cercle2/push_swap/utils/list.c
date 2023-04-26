/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:18:38 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/20 10:18:38 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lst_new(int data)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, int data)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = ft_lst_new(data);
	}
	else
		*lst = ft_lst_new(data);
}
