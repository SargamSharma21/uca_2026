#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void merge(int a[], int low, int mid, int high) {

    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    while(i <= mid && j <= high) {

        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

int CountInversion(int a[], int low, int high , int mid) {
    int count = 0;
    int right = mid + 1;
    for (int i = low ; i <= mid ; i++) {
        while (right <= high && a[i] > 2*a[right]) right++;
        count += (right-(mid+1));
    }
    return count;
}

int MerSort(int a[], int low, int high) {
    if(low >= high) return 0;
    int mid = (low + high) / 2;

    int left = MerSort(a, low, mid);
    int right = MerSort(a, mid + 1, high);
    int cross = CountInversion(a ,low , high , mid);

    merge(a, low, mid, high);
    return left + right + cross;
}


int main(){
    int a[] = {2 , 4, 3, 5 , 1};
    int size = 5;
    int count = MerSort(a , 0 , size-1);
    printf("%d\n" , count);
    printf("\n");
    return 0;
}