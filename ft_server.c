/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:56:57 by zel-hach          #+#    #+#             */
/*   Updated: 2022/02/17 13:08:03 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	returnstr(int tab[8], int *j, int stock)
{
	int	*t;

	t = (int [8]){1, 2, 4, 8, 16, 32, 64, 128};
	(*j)--;
	while (*j >= 0)
	{
		stock = stock + (tab[*j] * t[*j]);
		(*j)--;
	}
	ft_putchar(stock);
	*j = 0;
}

void	handler_sigusr_bonus(int signum, siginfo_t *info, void *secret)
{
	static int	i;
	static int	tab[8];
	int			stock;
	static int	pid_client;

	secret = NULL;
	stock = 0;
	if (info->si_pid != pid_client)
	{
		pid_client = info->si_pid;
		i = 0;
		stock = 0;
	}
	if (signum == SIGUSR1)
		tab[i++] = 0;
	else if (signum == SIGUSR2)
		tab[i++] = 1;
	if (i == 8)
		returnstr(tab, &i, stock);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr("====PID:\n");
	ft_putnbr(pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr_bonus;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putchar('\n');
	while (1)
		pause();
}
