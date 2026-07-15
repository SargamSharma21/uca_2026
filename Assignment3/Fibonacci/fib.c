#include <stdio.h>

int fib(int n){
    if(n == 1 || n == 0) return 1;
    return fib(n-1) + fib(n-2);

}

int main() {
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i = 0; fib(i) < n ; i++) {
        if(fib(i) % 2 == 0) {
            sum += fib(i);
        }
    }

    printf("The sum is: %d\n" , sum);
    return 0;
}