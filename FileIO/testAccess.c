#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

/* 判断某个文件是否有某种属性 */
int main()
{
    int ret = access("./heiheihei.c", F_OK);
    if(ret != 0)
    {
        perror("access error");
    }


    return 0;
}