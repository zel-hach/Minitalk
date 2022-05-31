/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:54:54 by zel-hach          #+#    #+#             */
/*   Updated: 2022/02/14 18:03:13 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_to_byte(int mess, int pid)
{
	int	k;
	int	i;

	k = -1;
	while (++k < 8)
	{
		i = mess % 2;
		mess = mess / 2;
		if (i == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("client: operation successful\n");
}

int	send_signals(char *message, int pid)
{
	int	d;

	d = 0;
	while (message[d])
	{
		convert_to_byte((unsigned char)message[d], pid);
		d++;
	}
	convert_to_byte(0, pid);
	return (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		ft_putstr("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	i = kill(pid, 0);
	if (pid > 0)
	{
		if (i == 0)
		{
			send_signals(argv[2], pid);
			signal(SIGUSR1, handler);
			pause();
		}
		else
			ft_putstr("pid incorrect\n");
	}
	else
		ft_putstr("pid incorrect\n");
	return (0);
}
