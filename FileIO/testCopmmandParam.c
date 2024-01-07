#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>


int main(int argc, const char *argv[])
{
    /* argc是参数的个数 */
    printf("argc : %d\n",argc);

    printf("argv[0] : %s\n", argv[0]);
    printf("argv[1] : %s\n", argv[1]);
    printf("argv[2] : %s\n", argv[2]);

    return 0;
}