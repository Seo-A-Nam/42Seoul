#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

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

void    handler(int signo)
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
        bit = 0;
        unsigned char c = msg_bit;
        write(1, &c, 1);
    }
}

int     main()
{
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    // client pid 출력.
    write(1, "Server PID : ", 14);
    ft_putnbr_fd((int)getpid(), 1);
    write(1, "\n", 1);
    // signal 입력 기다림.
    while (1)
        pause();
    return (0);
}
