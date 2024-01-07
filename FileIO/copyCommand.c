#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

#define size 1024
#define true 1
#define false 0

int copyFile(const char *fileName, const char *newFilename)
{
    if(!fileName)
    {
        return false;
    }

    int fd = open(fileName, O_RDWR);
    if (fd == -1)
    {
        perror ("open error");
    }

    int fd1 = open(newFilename, O_RDWR);
    if (fd1 == -1)
    {
        perror ("open error");
    }

    char buffer_read[size];

    /* 打开一个文件文件指针默认在开始 */
    while(1)
    {
        int readLen = read(fd, buffer_read, sizeof(buffer_read));
        if (readLen <= 0)
        {
            return true;
        }
        /* read后文件指针移位，接著在此處讀取 */
        write(fd1, buffer_read, readLen);
    }
    return true;
}



int main(int argc, const char *argv[])
{
    /* 如果命令行参数的个数不为三，就犯错 */
    if(argc != 3)
    {
        printf("argc param must be 3\n");
        return 0;
    }

    copyFile(argv[1], argv[2]);

    return 0;
}