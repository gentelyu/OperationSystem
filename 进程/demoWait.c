#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <wait.h>


int main()
{
    #if 0
    printf("hello world\n");
    /* 当进程没有子进程的时候 */
    wait(NULL);
    printf("hello world\n");
    #endif

    #if 1
    int num = 100;
    /* 创建一个子进程 */
    pid_t pid = fork();
    /* 创建完子进程后, 父进程不会自杀. */

    if (pid < 0)
    {
        perror("fork error");
        _exit(0);
    }
    if (pid == 0)
    {
        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process : childPid:%d, num:%d\n", childPid, num);

        /* 子进程sleep(120) */
        sleep(1);

        /* 进程退出 */
        int childState = 1;
        _exit(childState);
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent precess : parentPid:%d, num:%d\n", parentPid, num);
    }

    /* 父进程阻塞等待回收子进程的资源 */
    /* 返回值是: 回收的子进程ID号. */
    /* WEXITSTATUS 是一个宏，用于从子进程的终止状态中提取退出状态。
    在C语言中，当一个子进程终止时，其退出状态会被保存在一个特定的整数值中。
    WEXITSTATUS 宏可以将这个整数值转换为子进程的退出状态。*/
    int status = 0;
    pid_t waitPid = wait(&status);
    int ret = WEXITSTATUS(status);
    printf("waitPid = %d\n", waitPid);
    printf("status = %d\n", status);
    printf("ret = %d\n", ret);
    /* 这个status是存储子进程推出时的状态的整数值
        而通过WEXITSTATUS宏可以将具体的退出状态值(ret)提取出来 */

    printf("hello world\n");

    /* 对子进程不同状态返回值的判断 */
    if (WIFEXITED(status))
        printf("子进程正常返回\n");
    if (WIFSIGNALED(status))
        printf("子进程异常终止\n");
    if (WIFSTOPPED(status))
        printf("子进程当前处于暂停状态\n");
    if (WIFCONTINUED(status))
        printf("子进程当前从暂停状态转为正常工作状态\n");
    #endif
    return 0;
}