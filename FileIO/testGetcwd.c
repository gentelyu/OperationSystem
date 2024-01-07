#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

/* 获取当前进程的工作目录 */
/* 返回值是buf中保存当前进程工作目录的位置 */
#define BUFFER_SIZE 128

int main()
{
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    char *ptr = getcwd(buf, sizeof(buf) - 1);

    printf("buf: %s\n", buf);
    printf("ptr: %s\n", ptr);

    

    return 0;
}