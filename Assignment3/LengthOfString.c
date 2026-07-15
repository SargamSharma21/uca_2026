#include <stdio.h>
#include <string.h>

int my_strlen(const char *str) {
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

int main() {
    char str[] = "hello";
    int length = my_strlen(str);
    printf("%d\n" , length);
    return 0;
}