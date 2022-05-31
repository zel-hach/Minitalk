/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:36:18 by zel-hach          #+#    #+#             */
/*   Updated: 2022/02/17 13:17:25 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<sys/types.h>
# include<signal.h>
# include<stdio.h>
# include<stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	convert_to_byte(int mess, int pid);
void	handler(int signum);
int		send_signals(char *message, int pid);
void	handler_sigusr(int signum, siginfo_t *info, void *secret);
void	handler_sigusr_bonus(int signum, siginfo_t *info, void *secret);
void	returnstr_bonus(int tab[8], int *j, int stock, siginfo_t *info);
void	returnstr(int tab[8], int *j, int stock);
int		ft_isdigit(char c);

#endif
