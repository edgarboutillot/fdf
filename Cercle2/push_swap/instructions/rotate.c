/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:04:53 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/24 16:04:53 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	_rotate(t_list **top)
{
	t_list *first_elem;
	t_list *last_elem;

	first_elem = *top;
	if (!first_elem || first_elem->next == NULL)
		return ;
	last_elem = ft_lstlast(*top);
	last_elem->next = first_elem;
	*top = first_elem->next;
	first_elem->next = NULL;
}

void	rotate_a(t_list **top_a)
{
	ft_printf("ra\n");
	_rotate(top_a);
}

void	rotate_b(t_list **top_b)
{
	ft_printf("rb\n");
	_rotate(top_b);
}

void	rotate_both(t_list **top_a, t_list **top_b)
{
	ft_printf("rr\n");
	_rotate(top_a);
	_rotate(top_b);
}
