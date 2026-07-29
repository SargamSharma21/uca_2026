#include<stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int ans = getByte(0x12345678,1);
    printf("%x\n" , ans);
    return 0;
}