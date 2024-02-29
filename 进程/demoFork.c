#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
    int num = 0;

    /* 创建子进程 */
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        return 0;
    }
    if (pid == 0)
    {
        /* 子进程 */
        pid_t childPid = getpid();
        printf("childPid : %d\n", childPid);

        pid_t parentPid = getppid();
        printf("子进程中parentPid : %d\n", parentPid);

    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parentPid : %d\n", parentPid);
#if 0
        /* 如果父进程没有退出，那么子进程的ppid则为当前进程的pid */
        sleep(5);
#else
        /* 如果父进程已经退出了，子进程的父进程会被操作系统设置为init进程（PID为1）*/

#endif
    }


    return 0;
}