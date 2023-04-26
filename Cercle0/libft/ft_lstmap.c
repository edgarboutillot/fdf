/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:19:33 by edboutil          #+#    #+#             */
/*   Updated: 2022/11/17 19:23:45 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_free(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (!lst)
	{
		free(content);
		return (NULL);
	}
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*start;

	if (!lst && !f)
		return (0);
	start = NULL;
	while (lst)
	{
		new_lst = ft_lstnew_free(f(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_lst);
		lst = lst->next;
	}
	return (start);
}
