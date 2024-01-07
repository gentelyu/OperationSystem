#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    int ret = truncate("xixixi.c", 10);
    if (ret == -1)
    {
        perror("truncate");
        return 0;
    }






    return 0;
}