#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <string.h>



int main()
{
#if 1
    /* 使用lseek来计算文件大小 */
    int fd = open("./hello.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open error\n");
    }

    /* 在文件指定位置写入数据,覆盖写 */
    lseek(fd, 0, SEEK_SET);

    char * str = "yuchen";
    write(fd, str, strlen(str));
    close(fd);


#if 0
    off_t offset = lseek(fd, 0, SEEK_SET);
    printf("%ld\n", offset);
#endif


#endif
    return 0;
}