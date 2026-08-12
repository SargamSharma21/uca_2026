#include<stdio.h>
#include<string.h>
void encodeBase64(char s[]) {
    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int n = strlen(s);

    for(int i = 0 ; i < n ; i+=3) {
        int b1 = s[i];
        int b2 = (i+1 < n)? s[i+1] : 0;
        int b3 = (i+2 < n)? s[i+2] : 0;

        int n1 = b1 >> 2;
        int n2 = ((b1&3) << 4) | (b2 >> 4);
        int n3 = ((b2 & 15) << 2) | (b3 >> 6);
        int n4 = b3 & 63;
        
        printf("%c" , table[n1]);
        printf("%c" , table[n2]);

        if(i+1 < n) {
            printf("%c" , table[n3]);
        }
        else {
            printf("%c" , '=');
        }


        if(i+2 < n) {
            printf("%c" , table[n4]);
        }
        else {
            printf("%c" , '=');
        }


    }
}
int main() {
    char str[] = "Hello World";
    encodeBase64(str);
    return 0;

}