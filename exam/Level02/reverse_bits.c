/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:37:07 by edboutil          #+#    #+#             */
/*   Updated: 2023/01/26 18:54:07 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i--)
	{
		bit = bit * 2 + (octet % 2);
		octet /= 2;
	}
	return (bit);
}

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
