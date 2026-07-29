#include<stdio.h>
int powOftwo(int x) {
    return x > 0 && !!!(x & (x-1));
}
int main() {
    int ans = powOftwo(128);
    printf("%d\n" , ans);
}