// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int output = syscall(76, path, length);
	if (output < 0) {
		errno = output - 2*(output);
		return -1;
	}
	return output;
}
