/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:30:35 by yabtaour          #+#    #+#             */
/*   Updated: 2022/01/12 00:59:41 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_send(int pid, char chara, int i)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		if ((chara >> counter) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter++;
		if (i <= 10000)
			usleep(700);
		else
			usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("Execution should be : ./client PID String");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (0);
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i], i);
		i++;
	}
	ft_send(pid, '\n', 1);
}
