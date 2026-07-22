#include <stdio.h>
#include <stdlib.h>

int merge(int a[], int low, int mid, int high) {

    int i = low;
    int j = mid + 1;
    int k = 0;
    int count = 0;
    int temp[high - low + 1];

    while(i <= mid && j <= high) {

        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            count += (mid - i + 1);
        }
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
    return count;
}

int MerSort(int a[], int low, int high) {
    if(low >= high) return 0;
    int mid = (low + high) / 2;

    int left = MerSort(a, low, mid);
    int right = MerSort(a, mid + 1, high);
    // int cross = CountInversion(a ,low , high , mid);

    int count = merge(a, low, mid, high);
    return left + right + count;
}


int main(){
    int a[] = { 1 , 2 , 4 , 1 , 3 , 5};
    int size = 6;
    int count = MerSort(a , 0 , size-1);
    printf("%d\n" , count);
    printf("\n");
    return 0;
}