#include "minitalk.h"

int sig_ack = 0;

void    ack(int signo)
{
    (void)signo;
    sig_ack++;
} // 내가 한글자에 대한 시그널을 다 보냈을 때마다, 상대편에서 signal을 보내 sig_ack가 하나씩 늘어난다.

void    recieve_check(int sig_total)
{
    if (sig_ack == sig_total) // 보낸 총 글자 수와 받은 수신확인 signal의 개수가 같다면
        write(1,"Server recieved your message\n", 30);
    else
    {
        write(1,"[error] There was error while sending your message\n", 52);
    }
}

char    *process_whitespace(char *msg)
{
    int i = 0;
    int slash = 0, index = 0;
    char *result = (char *)malloc(sizeof(char)*ft_strlen(msg));

    if (result == 0)
        return (NULL);
    while (msg[i])
    {
        if (msg[i] == '\'')
            slash = 1;
        if (i > 0 && slash == 1)
        {
            slash = 0;
            if (msg[i] == 't')
                result[index++] = '\t';
            else if (msg[i] == 'v')
                result[index++] = '\v';
            else if (msg[i] == 'r')
                result[index++] = '\r';
            else if (msg[i] == 'f')
                result[index++] = '\f';
            else if (msg[i] == 'n')
                result[index++] = '\n';
            else if (msg[i] == '\'')
            {
                result[index++] = '\'';
                slash = 1;
            }
            else
            {
                result[index++] = '\'';
                result[index++] = msg[i];
            }
        }
        result[index++] = msg[i];
        i++;
    } 
    result[index] = '\0';
    return (result);
}

void    send_msg(int pid, char *msg, int *sig_total)
{
    int num, len, bit;

    len = ft_strlen(msg);
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
            너무 줄이면 시그널이 겹쳐져서 다 안보내짐. 30이 마지노 같음 */
        }
        (*sig_total)++; // 한 글자 보낼 때마다 증가
    }
}

int     main(int argc, char **argv)
{
    int sig_total = 0;
    char *msg;
    struct sigaction sa;

    if (argc != 3)
    {
        write(1, "[error] Wrong input formats\n", 29);
        return (1);
    }
    //수신 확인 시스템
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = ack;
    sigaction(SIGUSR1, &sa, (struct sigaction *)NULL); 
    // sigusr1, sigusr2만 허용 시그널이므로 sigusr1을 받아 수신 확인함.
    msg = process_whitespace(argv[2]); // 인자로 받은 문자열에서 텍스트로 되어있는 공백문자를 공백문자로 바꿈.
    send_msg(ft_atoi(argv[1]), msg, &sig_total);
    recieve_check(sig_total);
    return (0);
}
// 실행시 인자로 pid, 보낼 문자열 차례로 넣어줌