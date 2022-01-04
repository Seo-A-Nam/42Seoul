#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// kill 함수를 이용한 시그널 보내기
int     main(int argc, char **argv)
{
    int pid;
    char *msg;
    int num, result = 0;
    
    if (argc != 3)
    {
        perror("[error] Wrong input formats\n");
        return (1);
    }
    pid = atoi(argv[1]);
    msg = argv[2];
    int len = strlen(msg);
    for (int i = 0; i < len; i++)
    {
        num = (int)msg[i];
        for (int j = 7; j >= 0; --j) // 8 bit까지 표현
        {
            result = 0;
            result = num >> j & 1; // >> 연산 후 & 연산하기
            if (result == 0)
                kill(pid, SIGUSR1);
            else if (result == 1)
                kill(pid, SIGUSR2);
            usleep(50);
        }
    }
    return (0);
}
// 실행시 인자로 pid, 보낼 문자열 차례로 넣어줌