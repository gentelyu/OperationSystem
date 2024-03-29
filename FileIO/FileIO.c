#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>

/* 测试文件描述符的值从3开始 */
/* 0到2全部被系统单独使用了 */

int main()
{

    /* 打开文件 */
    int fd1 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if(fd1 == -1)
    {
        perror("open error\n");
    }
    printf("fd1 = %d\n", fd1);


    /* 打开文件 */
    int fd2 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if(fd2 == -1)
    {
        perror("open error\n");
    }
    printf("fd2 = %d\n", fd2);

    /* 打开文件 */
    int fd3 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if(fd3 == -1)
    {
        perror("open error\n");
    }
    printf("fd3 = %d\n", fd3);


    /* 打开文件 */
    int fd4 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if(fd4 == -1)
    {
        perror("open error\n");
    }
    printf("fd4 = %d\n", fd4);


    /* 关闭文件fd1 */
    close(fd1);

    /* 打开文件 */
    int fd5 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if(fd5 == -1)
    {
        perror("open error\n");
    }
    printf("fd5 = %d\n", fd5);
    
    /* 关闭文件描述符 */

    return 0;
}