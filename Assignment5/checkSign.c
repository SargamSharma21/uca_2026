#include<stdio.h>

int sign(int a) {
    return ((a >> 31) | (~(a >> 31) && !!a));
}

int main() {
    int ans = sign(0);
    printf("%d\n" , ans);
    return 0;
}