#include<stdio.h>

int bitXor(int a , int b) {
   return ~(~(~a & b) & ~(~b & a));
}

int main() {
    int ans = bitXor(154 , 143);
    printf("%d\n" , ans);
    return 0;
}