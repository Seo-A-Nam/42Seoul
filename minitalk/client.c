/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:02:47 by namseoa           #+#    #+#             */
/*   Updated: 2022/01/05 13:40:03 by namseoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig_ack;

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

static void	ack(int signo)
{
	(void)signo;
	g_sig_ack++;
}

static void	recieve_check(int sig_total)
{
	if (g_sig_ack != 0 && sig_total != 0 && (g_sig_ack == sig_total))
		write(1, "SUCCESS : Server recieved your message\n", 40);
	else
	{
		write(1, "[error] There was error while sending your message\n", 52);
	}
}

static void	send_msg(int pid, char *msg, int len, int *sig_total)
{
	int	bit;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 7;
		while (j >= 0)
		{
			bit = (int)msg[i] >> j & 1;
			if (bit == 0)
			{
				if (kill_(pid, SIGUSR1) == -1)
					return ;
			}
			else
				if (kill_(pid, SIGUSR2) == -1)
					return ;
			usleep(30);
			j--;
		}
		(*sig_total)++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					sig_total;
	char				*msg;

	sig_total = 0;
	g_sig_ack = 0;
	if (argc != 3 || ft_is_numstr(argv[1]) == 0)
	{
		write(1, "[error] Wrong input formats\n", 29);
		return (1);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = ack;
	if (sigaction(SIGUSR1, &sa, (struct sigaction *) NULL) == -1)
	{
		write(1, "[error] sigaction() : Failed to handle SIGUSR1 signal\n", 55);
		return (0);
	}
	msg = ft_convert_textws(argv[2]);
	send_msg(ft_atoi(argv[1]), msg, ft_strlen(msg), &sig_total);
	recieve_check(sig_total);
	free(msg);
	return (0);
}
