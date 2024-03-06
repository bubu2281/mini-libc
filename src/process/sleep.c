#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int __seconds) {
    struct timespec tim, tim2;
    tim.tv_sec = __seconds;
    tim.tv_nsec = 0;
    nanosleep(&tim, &tim2);
    return 0;
}
