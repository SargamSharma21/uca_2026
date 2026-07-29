#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = rand() % s + 1;
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Sort(int arr[] , int start , int end , int K) {
    if(start >= end) return;
    int pivot = start;
    int i = start+1;
    int x = start;
    for(int j = i; j <= end ; j++) {
        if (arr[j] < arr[pivot]) {
            swap(arr , j , ++x);
        }
    }
    swap(arr , x , pivot);
        if (x == K - 1)
        return;

    if (x > K - 1)
        Sort(arr, start, x - 1 , K);
    else
        Sort(arr, x + 1, end, K);

}

void print(int a[] , int s){
    int i;
    for(i = 0; i < s ; i++){
        printf("%d " , a[i]);
    }
    printf("\n");
}

int main() {
    struct timeval te;
    int size = 8000;
    int step = 4000;
    int i;
    for(i = 0; i < 8; i++){
        int a[size];
        int k = size/10;
        generateRandom(a, size);
        // print(a, size);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000000LL + te.tv_usec;

        Sort(a, 0 ,size-1 , k);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000000LL + te.tv_usec;

        printf("%lld\n", end - start);

        // print(a, size);

        size += step;
    }

    printf("\n");
    return 0;
}