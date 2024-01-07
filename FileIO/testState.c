#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024


void get_file_time(__time_t st_time)
{
    struct tm* info;
    info = localtime(&(st_time));
    printf("%02d %02d %02d:%02d\n",info->tm_mon+1,\
            info->tm_mday, info->tm_hour, info->tm_min);
}

int main()
{   
    struct stat bufStat;

    stat("./testState.c", &bufStat);

    printf("st_size : %ld\n", bufStat.st_size);
    printf("st_mode : %d\n", bufStat.st_mode);

    /* 最后一次访问时间 */
    get_file_time(bufStat.st_atime);
    /* 最后一次修改时间 */
    get_file_time(bufStat.st_mtime);
    /* 最后一次改变时间（属性）*/
    get_file_time(bufStat.st_ctime);


/* 配置文件 */
    FILE * pfd = popen("md5sum testState.c", "r");
    if (pfd == NULL)
    {
        perror("popen error!");
        return 0;
    }

    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    fread(buf, sizeof(buf) - 1, 1, pfd);

    printf("buff : %s\n", buf);

    pclose(pfd);

    return 0;
}