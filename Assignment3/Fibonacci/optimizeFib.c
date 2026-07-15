#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int sum = 0;
    int a = 1;
    int b = 1;
    while(b < n) {
        int c = a + b;
        if ( c % 2 == 0){
            sum += c;
        }
        a = b;
        b = c;
    }

    printf("The sum is: %d\n" , sum);
    return 0;
}