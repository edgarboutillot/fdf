/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:07:03 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/24 16:07:03 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

static void	_reverse_rotate(t_list **top)
{
	t_list *first_elem;
	t_list *last_elem;

	ft_printf("ra");
	first_elem = *top;
	if (!first_elem || first_elem->next == NULL)
		return ;
	last_elem = ft_lstlast(*top);
	last_elem->next = first_elem;
	*top = first_elem->next;
	first_elem->next = NULL;
}

void	reverse_rotate_a(t_list **top_a)
{
	ft_printf("rra\n");
	_reverse_rotate(top_a);
}

void	reverse_rotate_b(t_list **top_b)
{
	ft_printf("rrb\n");
	_reverse_rotate(top_b);
}

void	reverse_rotate_both(t_list **top_a, t_list **top_b)
{
	ft_printf("rrr\n");
	_reverse_rotate(top_a);
	_reverse_rotate(top_b);
}
