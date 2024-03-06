// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int output = syscall(4, path, buf);
	if (output < 0) {
		errno = output - 2*(output);
		return -1;
	}
	return output;
}
