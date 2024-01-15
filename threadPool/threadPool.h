#ifndef __THREAD_H_
#define __THREAD_H_

#include <pthread.h>

typedef struct threadpool_t
{
    /* 线程池中的线程 */
    pthread_t threadId;

    /* 最小的线程数 */
    int minThreads;

    /* 最大线程数 */
    int maxThreads;


}threadpool_t;


#endif