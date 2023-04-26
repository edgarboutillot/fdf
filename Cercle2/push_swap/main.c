/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:19:18 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/20 10:19:18 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_print_list(t_list *top)
{
	while (top)
	{
		ft_printf("%d\n", top->data);
		top = top->next;
	}
}

void	print_stacks(t_list *a, t_list *b)
{
	ft_printf("-----Stack A------\n\n");
	ft_print_list(a);
	ft_printf("\n");
	ft_printf("-----Stack B------\n\n");
	ft_print_list(b);
	ft_printf("\n");
}

static t_exit	_malloc_stack(t_list **top_a, t_list **top_b)
{
	*top_a = malloc(sizeof(t_list));
	if (!*top_a)
		return (ERROR_MALLOC);
	*top_b = malloc(sizeof(t_list));
	if (!*top_b)
		return (free(top_a), ERROR_MALLOC);
	return (SUCCESS);
}

void	create_list(char **av, t_list **top_a)
{
	int			i;
	long int 	min_max;

	i = 0;
	*top_a = NULL;
	while (av[i])
	{
		min_max = ft_atoi(av[i]);
		if (min_max < INT_MIN || min_max > INT_MAX)
		{
			ft_printf("Error\n");
			exit(0);
		}
		ft_lstadd_back(top_a, ft_atoi(av[i]));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*top_a;
	t_list	*top_b;

	ac--;
	av++;
	if (_malloc_stack(&top_a, &top_b) == ERROR_MALLOC)
		return (ERROR_MALLOC);
	top_a = NULL;
	top_b = NULL;
	parsing(av);
	create_list(av, &top_a);
	//swap(lst_a);
	//reverse_rotate(top_a);
	rotate_a(&top_a);
	print_stacks(top_a, top_b);
	return (SUCCESS);
}
