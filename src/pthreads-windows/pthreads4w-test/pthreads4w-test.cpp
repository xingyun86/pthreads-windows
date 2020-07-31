// pthreads4w-test.cpp : Defines the entry point for the application.
//

#include "pthreads4w-test.h"
#include <pthread.h>

double waste_time(long n)
{

    double res = 0;
    long i = 0;
    while (i < n * 200000) {
        i++;
        res += sqrt(i);
    }
    return res;
}

void* thread_func(void* param)
{
    cpu_set_t cpu_set = { 0 };

    memset(&cpu_set, 0, sizeof(cpu_set));
    cpu_set.cpuset[0] = 0x01;/* processor 0 */

    /* bind process to processor 0 */
    if (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set), (const cpu_set_t*)&cpu_set) < 0) {
        perror("pthread_setaffinity_np");
    }

    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set), (cpu_set_t*)&cpu_set);
    /* waste some time so the work is visible with "top" */
    printf("[cpu %d] result: %f\n", cpu_set.cpuset[0], waste_time(2000));

    memset(&cpu_set, 0, sizeof(cpu_set));
    cpu_set.cpuset[0] = 0x02;/* process switches to processor 1 now */
    if (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set), (const cpu_set_t*)&cpu_set) < 0) {
        perror("pthread_setaffinity_np");
    }

    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set), (cpu_set_t*)&cpu_set);
    /* waste some more time to see the processor switch */
    printf("[cpu %d] result: %f\n", cpu_set.cpuset[0], waste_time(2000));

    return 0;
}

int main(int argc, char ** argv)
{
	std::cout << "Hello CMake." << std::endl;
	
	pthread_t my_thread;

	if (pthread_create(&my_thread, NULL, thread_func, NULL) != 0) {
		perror("pthread_create");
	}
	pthread_exit(NULL);

	return 0;
}
