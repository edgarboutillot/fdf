/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:18:22 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/20 10:18:22 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *lst)
{
	int	tmp;

	tmp = lst->data;
	lst->data = lst->next->data;
	lst->next->data = tmp;
}

//void	reverse_rotate(t_start *top_a)
//{
//	t_list	*tmp;
//	t_list	*tmp2;
//
//	tmp = top_a->st_next;
//	tmp2 = ft_lstlast(tmp);
//	while (tmp->next->next)
//	{
//		tmp = tmp->next;
//	}
//	tmp->next = NULL;
//	tmp2->next = top_a->st_next;
//	top_a->st_next = tmp2;
//}

void	push_b(t_list *lst_a, t_list *lst_b)
{
	lst_b->data = 0;
	lst_b->next = NULL;
	ft_printf("%d\n", lst_a->data);
}
