// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	int output = syscall(77, fd, length);
	if (output == -22 || output == -9) {
		errno = output - 2*(output);
		return -1;
	}
	return output;
}
