/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:17:24 by yabtaour          #+#    #+#             */
/*   Updated: 2022/01/12 00:59:43 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *content)
{
	static int	c;
	static int	counter;
	static int	pid;

	(void)content;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		counter = 0;
	}
	if (signal == SIGUSR1)
		c = c | 1 << counter;
	counter++;
	if (counter == 8)
	{
		write(1, &c, 1);
		c = 0;
		counter = 0;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
