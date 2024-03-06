
#ifndef	__TIME_H__
#define	__TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

struct timespec {
	long		tv_sec;
	long		tv_nsec;
};

int nanosleep(struct timespec *rqtp, struct timespec *rmtp);
unsigned int sleep(unsigned int __seconds);

#ifdef __cplusplus
}
#endif

#endif
