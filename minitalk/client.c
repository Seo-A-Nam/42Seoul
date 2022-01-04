#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int sig_ack = 0;
int sig_total = 0;

void    ack(int signo)
{
    sig_ack++;
} // 내가 한글자에 대한 시그널을 다 보냈을 때마다, 상대편에서 signal을 보내 sig_ack가 하나씩 늘어난다.

void    recieve_check()
{
    if (sig_ack == sig_total) // 보낸 총 글자 수와 받은 수신확인 signal의 개수가 같다면
        write(1,"Server recieved your message\n", 30);
    else
    {
        write(1,"[error] There was error while sending your message\n", 52);
    }
}

void    send_msg(int pid, char *msg)
{
    int num, len, bit;
    
    len = strlen(msg);
    for (int i = 0; i < len; i++)
    {
        num = (int)msg[i];
        for (int j = 7; j >= 0; --j) // 10진수 숫자를 2진수(8비트)로 바꾸기
        {
            bit = 0;
            bit = num >> j & 1;
            if (bit == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(30); 
            /* 좀더 시그널을 빠르게 만들려면 usleep()의 매개변수를 줄이면 되는데, 
            너무 줄이면 시그널이 겹쳐져서 다 안보내짐. */
        }
        sig_total++; // 한 글자 보낼 때마다 증가
    }
}

int     main(int argc, char **argv)
{
    struct sigaction sa;

    if (argc != 3)
    {
        perror("[error] Wrong input formats\n");
        return (1);
    }
    //수신 확인 시스템
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = ack;
    sigaction(SIGUSR1, &sa, (struct sigaction *)NULL); 
    // sigusr1, sigusr2만 허용 시그널이므로 sigusr1을 받아 수신 확인함.
    send_msg(atoi(argv[1]), argv[2]);
    recieve_check();
    return (0);
}
// 실행시 인자로 pid, 보낼 문자열 차례로 넣어줌