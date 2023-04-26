/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:39:17 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/24 16:46:36 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list	t_list;
typedef struct s_env	t_env;
typedef enum e_exit		t_exit;

enum e_exit
{
	SUCCESS,
	ERROR,
	ERROR_MALLOC,
};

struct s_list
{
	int		data;
	t_list	*next;
};

struct s_env
{
	t_list	*lst_a;
	t_list	*lst_b;
};

// UTILS --------------------------------------------------

int			ft_atoi(const char *str);
t_list		*ft_lst_new(int data);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, int data);
int			ft_printf(const char *format, ...);
int			parsing(char **av);
int 		is_digit(char c);
int			str_cmp(const char *s1, const char *s2);

// INSTRUCTIONS -------------------------------------------

void	swap(t_list *lst);
void	rotate_a(t_list **top_a);
void	rotate_b(t_list **top_b);
void	rotate_both(t_list **top_a, t_list **top_b);
void	push_b(t_list *lst_a, t_list *lst_b);

#endif
