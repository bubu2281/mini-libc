// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	int output = syscall(8, fd, offset, whence);
	if (output < 0) {
		errno = output - 2*(output);
		return -1;
	}
	return output;
}
