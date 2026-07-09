#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = rand() % s + 1;
    }
}

void generateAscending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = i;
    }
}

void generateDescending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = s - i;
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// void BubSort(int a[], int n) {
//     int i;
//     int j;

//     for(i = 0; i < n; i++) {
//         int swapped = 0;

//         for(j = 1; j < n - i; j++) {

//             if(a[j] < a[j - 1]) {
//                 swap(a, j, j - 1);
//                 swapped = 1;
//             }
//         }

//         if(swapped == 0)
//             break;
//     }
// }

// void InsSort(int a[], int n) {

//     int i, j, key;

//     for(i = 1; i < n; i++) {

//         key = a[i];
//         j = i - 1;

//         while(j >= 0 && a[j] > key) {
//             a[j + 1] = a[j];
//             j--;
//         }

//         a[j + 1] = key;
//     }
// }

// void SelecSort(int a[], int n) {

//     int i, j, min;

//     for(i = 0; i < n - 1; i++) {

//         min = i;

//         for(j = i + 1; j < n; j++) {

//             if(a[j] < a[min])
//                 min = j;
//         }

//         if(min != i)
//             swap(a, i, min);
//     }
// }

// void merge(int a[], int low, int mid, int high) {

//     int i = low;
//     int j = mid + 1;
//     int k = 0;

//     int temp[high - low + 1];

//     while(i <= mid && j <= high) {

//         if(a[i] < a[j])
//             temp[k++] = a[i++];
//         else
//             temp[k++] = a[j++];
//     }

//     while(i <= mid)
//         temp[k++] = a[i++];

//     while(j <= high)
//         temp[k++] = a[j++];

//     for(i = low, k = 0; i <= high; i++, k++)
//         a[i] = temp[k];
// }

// void MerSort(int a[], int low, int high) {

//     if(low < high) {

//         int mid = (low + high) / 2;

//         MerSort(a, low, mid);
//         MerSort(a, mid + 1, high);

//         merge(a, low, mid, high);
//     }
// }

// int partition(int a[], int low, int high) {

//     int pivot = a[high];
//     int i = low - 1;
//     int j;

//     for(j = low; j < high; j++) {

//         if(a[j] < pivot) {

//             i++;
//             swap(a, i, j);
//         }
//     }

//     swap(a, i + 1, high);

//     return i + 1;
// }

// void QuiSort(int a[], int low, int high) {

//     if(low < high) {

//         int p = partition(a, low, high);

//         QuiSort(a, low, p - 1);
//         QuiSort(a, p + 1, high);
//     }
// }


void heapify(int a[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i) {

        swap(a, i, largest);

        heapify(a, n, largest);
    }
}

void Sort(int a[], int n) {

    int i;

    for(i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for(i = n - 1; i > 0; i--) {

        swap(a, 0, i);

        heapify(a, i, 0);
    }
}

void print(int a[] , int s){
    int i;
    for(i = 0; i < s ; i++){
        printf("%d " , a[i]);
    }
    printf("\n");
}

int main(){
    struct timeval te;
    int size = 8000;
    int step = 4000;
    int i;
    for(i = 0; i < 8; i++){
        int a[size];

        generateRandom(a, size);
        // generateAscending(a, size);
        // generateDescending(a, size);
        // print(a, size);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

        Sort(a, size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

        printf("%lld\n", end - start);

        // print(a, size);

        size += step;
    }

    printf("\n");
    return 0;
}