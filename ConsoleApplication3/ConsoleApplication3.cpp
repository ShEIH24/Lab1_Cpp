#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

// Пользовательская реализация strcpy
char* my_strcpy(char* dest, const char* src) {
    char* original_dest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

int main() {
    const char* source = "Hello, World!";
    char dest1[20];
    char dest2[20];

    // Использование безопасной функции strcpy_s
    strcpy_s(dest1, sizeof(dest1), source);
    printf("Standard function strcpy_s:\n");
    printf("String: %s\n", source);
    printf("The copied string: %s\n\n", dest1);

    // Использование пользовательской функции my_strcpy
    my_strcpy(dest2, source);
    printf("The user function my_strcpy:\n");
    printf("String: %s\n", source);
    printf("The copied string: %s\n", dest2);

    return 0;
}