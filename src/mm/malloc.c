// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *pointer;
	pointer = mmap(NULL, size + sizeof(int), PROT_READ | PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
	if (pointer == MAP_FAILED) {
		return NULL;
	}
	int *mem_size = (int *)pointer;
	*mem_size = size;
	mem_size++;
	return (void *)mem_size;
}

void *calloc(size_t nmemb, size_t size)
{
	size = size * nmemb;
	void *pointer;
	pointer = mmap(NULL, size + sizeof(int), PROT_READ | PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
	if (pointer == MAP_FAILED) {
		return NULL;
	}
	int *mem_size = (int *)pointer;
	*mem_size = size;
	mem_size++;
	char *iter = (char *)mem_size;
	for(unsigned int i = 0; i < size; i++) {
		iter[i] = 0;
	}
	return (void *)mem_size;
}

void free(void *ptr)
{
	int *mem_size_pointer = (int *)ptr;
	mem_size_pointer--;
	int mem_size = *mem_size_pointer;
	munmap(mem_size_pointer, mem_size + sizeof(int));
}

void *realloc(void *ptr, size_t size)
{
	int *mem_size_pointer = (int *)ptr;
	mem_size_pointer--;
	unsigned int mem_size = *mem_size_pointer;
	char *new_pointer = malloc(size);
	if(!new_pointer) return NULL;
	int size_data_to_be_copied;
	if (size > mem_size) {
		size_data_to_be_copied = mem_size;
	} else {
		size_data_to_be_copied = size;
	}
	char *ptr_copy = (char *)ptr;
	for (int i = 0; i < size_data_to_be_copied; i++) {
		new_pointer[i] = ptr_copy[i];
	}
	free(ptr);
	return (void *)new_pointer;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb*size);
}
