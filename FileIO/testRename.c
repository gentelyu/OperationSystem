#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

/* 重命名文件名,类似于mv */

int main()
{
    int ret = rename("./hhh.c", "xxx.c");
    if(ret == -1)
    {
        perror("rename error");
    }

    return 0;
}