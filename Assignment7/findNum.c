#include<stdio.h>

int main() {
    int arr[] =  {1, 2, 4, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    int result = 0;
    for(int bit = 0 ; bit < 32 ; bit++) {
        int count = 0;

        for(int j = 0 ; j < len ; j++) {
            if((arr[j] & (1 << bit)) != 0) {
                count++;
            } 
        }

        if(count % 3 != 0) {
            result |= (1 << bit);
        }
    }
    printf("%d" , result);
    return 0;
}