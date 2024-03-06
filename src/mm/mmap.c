// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	if (fd > 2) {
		errno = EBADF;
		return MAP_FAILED;
	}
	if (flags == MAP_ANONYMOUS) {
		errno = EINVAL;
		return MAP_FAILED;
	}
	return (void *)syscall(9, addr, length, prot, flags, fd, offset);
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	return (void *)syscall(25, old_address, old_size, new_size, flags);
}

int munmap(void *addr, size_t length)
{
	return syscall(11, addr, length);
}
