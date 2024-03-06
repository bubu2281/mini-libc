// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	int output = syscall(2, filename, flags);
	if (output < 0) {
		errno = output - 2*(output);
		return -1;
	}
	return output;
}
