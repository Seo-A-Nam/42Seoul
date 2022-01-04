#include "minitalk.h"

void    get_msg(int signo, siginfo_t *info, void *a) // 시그널 핸들러.
{
    static int bit = 0;
    static int msg_bit = 0;

    (void)a;
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
        kill(info->si_pid, SIGUSR1); // 한 글자마다 수신 확인 시그널 보내줌
        bit = 0;
        unsigned char c = msg_bit;
        write(1, &c, 1);
    }
} // 따로 호출해주지 않아도, signal이 들어오면 알아서 호출되는 함수 (시그널 핸들러)

void    print_serverPid()
{
    write(1, "Server PID : ", 14);
    ft_putnbr_fd((int)getpid(), 1);
    write(1, "\n", 1);
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
    while (1)
    {
        pause();
    }
    return (0);
}
