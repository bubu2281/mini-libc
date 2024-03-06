// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int output = syscall(5, fd, st);
	if (output < 0) {
		errno = output - 2*(output);
		return -1;
	}
	return output;
}
