#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

struct timespec {
	long		tv_sec;
	long		tv_nsec;
};

int nanosleep(struct timespec *rqtp, struct timespec *rmtp) {
    return syscall(35, rqtp, rmtp);
}
