/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:05:10 by edboutil          #+#    #+#             */
/*   Updated: 2023/03/07 13:16:53 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	usleep(500);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		ft_printf("Error\n");
	pid = getpid();
	ft_printf("Server PID is : %d\n", pid);
	ft_printf("Waiting for a message...\n");
	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
