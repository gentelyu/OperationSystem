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
        printf("childPid : %dn\n", childPid);

        pid_t parentPid = getppid();
        printf("parentPid : %dn\n", parentPid);

    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parentPid : %dn\n", parentPid);
    }


    return 0;
}