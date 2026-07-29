#include <stdio.h>

int bang(int x) {
   return ((x | (~x+1)) >> 31) + 1;
}

int main() {
    int ans = bang(19);
    printf("%d\n" , ans);
}