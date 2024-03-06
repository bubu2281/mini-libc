#include <internal/syscall.h>

int puts(const char *str) {
    const char *str_copy = str;
    int size_str;
    for (size_str = 0; *str_copy != '\0'; size_str++, str_copy++) {}
    size_str++;
    syscall(1, 1, str, size_str);
    syscall(1, 1, "\n", 1);
    return 1;
}
