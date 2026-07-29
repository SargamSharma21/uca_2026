#include<stdio.h>

int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);   
    return !((((x << shift) >> shift) ^ x));
}

int main() {
    int ans = fitsBits(-4 , 3);
    printf("%d\n" , ans);
    return 0;
}