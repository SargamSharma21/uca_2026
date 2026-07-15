#include <stdio.h>
#include <string.h>

void url_encode(char *str, int true_length) {
    int spaceCount = 0;
    for(int i = 0; i <true_length ; i++) {
        if(str[i] == ' ') {
            spaceCount+=1;
        }
    }
    int new_len = true_length + (2*spaceCount);
    str[new_len] = '\0';
    for(int i = true_length - 1 ; i >= 0 ; i--) {
        if( str[i] == ' ') {
            str[new_len - 1] = '0';
            str[new_len - 2] = '2';
            str[new_len - 3] = '%';
            new_len -= 3;
        }

        else {
            str[new_len - 1] = str[i];
            new_len -= 1;
        }
    }
}

int main() {
    char str[] = "Hello World    ";
    int truelen = 11;
    url_encode(str , truelen);
    printf("%s\n" , str );
    return 0;
}