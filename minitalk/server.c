#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int serverPid = 0;

static void	write_nbr_fd(int n, int fd)
{
	char	c;

	c = (n % 10) + '0';
	if (n >= 10)
		write_nbr_fd(n / 10, fd);
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	write_nbr_fd(n, fd);
}
// write()를 통해 정수를 출력

void    get_msg(int signo, siginfo_t *info, void *a)
{
    static int bit = 0;
    static int msg_bit = 0;

    // 2배 곱하는 걸 곱셈 연산자가 아닌 비트연산으로. 비트연산이 곱셈연산과 속도면에서 50~100배 이상 차이 난다.
    if (signo == SIGUSR1)
    {
        msg_bit = msg_bit<<1;
        bit++;
    }
    if (signo == SIGUSR2)
    {
        msg_bit = (msg_bit<<1) + 1;
        bit++;
    }
    if (bit == 8)
    {
        serverPid = info->si_pid;
        bit = 0;
        unsigned char c = msg_bit;
        write(1, &c, 1);
    }
}

void    print_serverPid()
{
    write(1, "Server PID : ", 14);
    ft_putnbr_fd((int)getpid(), 1);
    write(1, "\n", 1);
}

void    wait_msg()
{
    while (1)
    {
        pause();
        if (serverPid != 0)
        {
            kill(serverPid, SIGUSR1);
            serverPid = 0;
        }
    }
}

int     main()
{
    struct sigaction sa;
    // 특정 signal을 받았을 때 호출되는 함수(handler)를 지정함. 
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_sigaction = get_msg;
    sigaction(SIGUSR1, &sa, (struct sigaction *)NULL);
    sigaction(SIGUSR2, &sa, (struct sigaction *)NULL);
    // client pid 출력.
    print_serverPid();
    // signal 입력 기다림.
    wait_msg();
    return (0);
}
