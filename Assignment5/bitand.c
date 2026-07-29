#include<stdio.h>

int bitAnd(int a , int b) {
   return ~(~a | ~b);
}

int main() {
    int ans = bitAnd(6 , 5);
    printf("%d\n" , ans);
}