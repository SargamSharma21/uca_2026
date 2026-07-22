#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int index[] , int low, int mid, int high , int ans[]) {

    int i = low;
    int j = mid + 1;
    int k = 0;
    int count = 0;
    int temp[high - low + 1];

    while(i <= mid && j <= high) {

        if(a[index[j]] < a[index[i]]) {
            temp[k++] = index[j++];
            count++;
        }
        else {
            ans[index[i]] += count;
            temp[k++] = index[i++];
        }
        // printf("%d\n" , count);
    }

    while(i <= mid) {
        ans[index[i]] += count;
        temp[k++] = index[i++];
    }

    while(j <= high)
        temp[k++] = index[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        index[i] = temp[k];
}

void MerSort(int a[],int index[] , int low, int high , int ans[]) {
    if(low >= high) return;
    int mid = (low + high) / 2;

    MerSort(a , index , low, mid , ans);
    MerSort(a, index , mid + 1, high , ans);

    merge(a, index, low, mid, high , ans);
}


int main(){
    int a[] = { 5 , 2  , 6 , 1};
    int n = 4;
    int index[n];
    int ans[n];

    for (int i = 0; i < n; i++) {
        index[i] = i;
        ans[i] = 0;
    }
    MerSort(a , index , 0 , n-1 , ans);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}