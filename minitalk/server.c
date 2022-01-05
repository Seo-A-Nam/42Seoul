/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:11:40 by namseoa           #+#    #+#             */
/*   Updated: 2022/01/05 12:30:41 by namseoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	kill_(int targetPID, int signo)
{
	if (kill(targetPID, signo) == -1)
	{
		if (errno == EPERM)
		{
			write(1, "[error] kill() : Not enough permission!\n", 41);
		}
		else if (errno == ESRCH)
		{
			write(1, "[error] kill() : Cannot find the process of pid [", 50);
			ft_putnbr_fd(targetPID, 1);
			write(1, "]\n", 3);
		}
		else if (errno == EINVAL)
		{	
			write(1, "[error] kill() : Invalid signo", 31);
			ft_putnbr_fd(signo, 1);
			write(1, "\n", 1);
		}
		else
			write(1, "[error] kill()\n", 16);
		return (-1);
	}
	return (0);
}

static void	get_msg(int signo, siginfo_t *info, void *a)
{
	static int		bit;
	static int		msg_bit;
	unsigned char	c;

	(void)a;
	if (signo == SIGUSR1)
	{
		msg_bit = (msg_bit << 1);
		bit++;
	}
	if (signo == SIGUSR2)
	{
		msg_bit = (msg_bit << 1) + 1;
		bit++;
	}
	if (bit == 8)
	{
		if (kill_(info->si_pid, SIGUSR1) == -1)
			return ;
		bit = 0;
		c = msg_bit;
		write(1, &c, 1);
	}
}

static void	print_serverpid(void)
{
	write(1, "Server PID : ", 14);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_sigaction = get_msg;
	if (sigaction(SIGUSR1, &sa, (struct sigaction *) NULL) == -1)
	{
		write(1, "[error] sigaction() : Failed to handle SIGUSR1 signal\n", 55);
		return (0);
	}
	if (sigaction(SIGUSR2, &sa, (struct sigaction *) NULL) == -1)
	{
		write(1, "[error] sigaction() : Failed to handle SIGUSR2 signal\n", 55);
		return (0);
	}
	print_serverpid();
	while (1)
	{
		pause();
	}
	return (0);
}
