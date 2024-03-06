// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	for (unsigned int i = 0; i <= strlen(source); i++) {
		destination[i] = source[i];
	}
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	for (unsigned int i = 0; i <= strlen(source) && i < len; i++) {
		if (i >= len) {
			destination[i] = '\0';
			break;
		}
		destination[i] = source[i];
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	const int len_source = strlen(source);
	const int len_destination = strlen(destination);
	for (int i = 0; i <= len_source; i++) {
		destination[i + len_destination] = source[i];
	}
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	const unsigned int len_source = strlen(source);
	const unsigned int len_destination = strlen(destination);
	for (unsigned int i = 0; i <= len_source; i++) {
		if (i >= len) {
			destination[i + len_destination] = '\0';
			break;
		}
		destination[i + len_destination] = source[i];
	}
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	const char *iter1 = str1;
	const char *iter2 = str2;
	while((*iter1 != '\0') && (*iter2 != '\0')) {
		if(*iter1 != *iter2) {
			return *iter1 - *iter2;
		}
		iter1++;
		iter2++;
	}
	if (*iter1 == *iter2) {
		return 0;
	}
	if (*iter1 == '\0') {
		return -1;
	}
	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	unsigned int steps = 0;
	const char *iter1 = str1;
	const char *iter2 = str2;
	while((*iter1 != '\0') && (*iter2 != '\0') && steps < len) {
		if(*iter1 != *iter2) {
			return *iter1 - *iter2;
		}
		iter1++;
		iter2++;
		steps++;
	}
	if (*iter1 == *iter2 || len == steps) {
		return 0;
	}
	if (*iter1 == '\0') {
		return -1;
	}
	return 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *iter = (char *)str;
	while (*iter != '\0') {
		if (*iter == c) {
			return iter;
		}
		iter++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	const unsigned int len = strlen(str);
	char *iter = (char *)str;
	for(int i = len - 1; i >= 0; i--) {
		if (iter[i] == c) {
			return iter + i;
		}
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	const int hay_len = strlen(haystack);
	const int needle_len = strlen(needle);
	for (int i = 0; i < hay_len - needle_len; i++) {
		int is_the_same = 1;
		for (int j = 0; j < needle_len; j++) {
			if (haystack[j + i] != needle[j]) {
				is_the_same = 0;
				break;
			}
		}
		if (is_the_same == 1) {
			char *aux = (char *)haystack;
			return aux + i;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const unsigned int hay_len = strlen(haystack);
	const unsigned int needle_len = strlen(needle);
	for (int i = hay_len - needle_len - 1; i >= 0; i--) {
		unsigned int is_the_same = 1;
		for (unsigned int j = 0; j < needle_len; j++) {
			if (haystack[j + i] != needle[j]) {
				is_the_same = 0;
				break;
			}
		}
		if (is_the_same == 1) {
			char *aux = (char *)haystack;
			return aux + i;
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest_char = (char *)destination;
	const char *source_char = (char *)source;
	for (unsigned int i = 0; i <= strlen(source_char) && i < num; i++) {
		dest_char[i] = source_char[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest_char = (char *)destination;
	const char *source_char = (char *)source;
	char buffer[100];
	for(unsigned int i = 0; i < num; i++) {
		buffer[i] = 0;
	}
	for (unsigned int i = 0; i <= strlen(source_char) && i < num; i++) {
		buffer[i] = source_char[i];
	}
	for (unsigned int i = 0; i <= strlen(buffer) && i < num; i++) {
		dest_char[i] = buffer[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char *ptr1_char = ptr1;
	const char *ptr2_char = ptr2;
	return strncmp(ptr1_char, ptr2_char, num);
}

void *memset(void *source, int value, size_t num)
{
	char *source_char = source;
	for (unsigned int i = 0 ; i < num; i++) {
		source_char[i] = value;
	}
	return source;
}
