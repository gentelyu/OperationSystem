#include <stdio.h>
#include <unistd.h>         // _exit()
#include <errno.h>
#include <stdlib.h>         // exit()
#include <sys/types.h>
#include <sys/wait.h>       // wait()

/* 
    _exit()是系统调用，它会直接退出程序并返回一个整数值给操作系统，
    exit()则是一个库函数，在退出程序之前还会执行一些清理工作，如关闭文件、释放内存等，底层封装的是_exit()。
    exit()可以使用atexit()注册的函数，更安全*/

int main()
{
    int count = 0;

    /* 创建进程 */
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(-1);
    }

    if (pid == 0)
    {
        /* 子进程 */
        pid_t childPid = getpid();
        
        while(count < 10)
        {
            count++;
            printf("childPid:%d\n", childPid);
            sleep(2);
        }

        /* 子进程退出 */
        _exit(0);
    }   
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();

        while(count < 5)
        {
            count++;
            printf("parentPid:%d\n", parentPid);
            sleep(2);
        }
        
        /* 等待子进程退出 */
        wait(NULL);
    }
    /* 子进程已经结束了, 那么子进程的代码就不会到这边了. */
    
    printf("hello world\n");
    return 0;
}