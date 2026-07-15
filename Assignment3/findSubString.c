#include <stdio.h>
#include <string.h>
int find_substring(const char *haystack, const char *needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    int out = -1;
    int j = 0;
    for(int i = 0; i < len1 ; i++) {
        if(haystack[i] == needle[j]){
            if( j == 0) out = i;
            j++;
            if( j == len2 ) return out;
        }
        else{
            if( j != 0 ) {
                j = 0;
                out = -1;
                i--;
            }
        }
    }
    return -1;
}

int main() {
    char str1[] = "Embedded Systems";
    char str2[] = "Sys";
    int i = find_substring(str1 , str2);
    printf("%d\n" , i);
    return 0;
}