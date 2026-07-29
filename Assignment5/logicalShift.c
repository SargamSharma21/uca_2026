#include<stdio.h>

int logicalShift(int x, int n) {
   return (x >> n) & 0x0FFFFFFF;
}

int main() {
   int ans = logicalShift(0x87654321,4);
   printf("%x\n" , ans);
   return 0;
}