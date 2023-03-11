/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:16:24 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/19 14:55:06 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define BASE_DEC "0123456789"
# define BASE_HEXL "0123456789abcdef"
# define BASE_HEXU "0123456789ABCDEF"

# define LLU_INT long long unsigned int

void	ft_putchar(char c, int *len);
int		ft_printf(const char *format, ...);
void	ft_conversion(va_list args, const char format, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_unsigned(unsigned int n, int *len);
void	ft_putnbr_base(unsigned long long int n, char *base, \
			int len_base, int *len);

#endif
