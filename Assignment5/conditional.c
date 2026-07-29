#include<stdio.h>

int conditional(int x , int y , int z) {
    return ((~x+1) & y | (~x) & z);
}

int main() {
    int ans = conditional(0 , 1 , 0);
    printf("%d\n" , ans);
}