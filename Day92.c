/*Problem: Implement Quick Sort using partition method (Lomuto or Hoare).*/

code:

#include <stdio.h>
 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int lomuto_partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
 
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
 
void quick_sort_lomuto(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomuto_partition(arr, low, high);
        quick_sort_lomuto(arr, low, pi - 1);
        quick_sort_lomuto(arr, pi + 1, high);
    }
}
 
int hoare_partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
 
    while (1) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}
 
void quick_sort_hoare(int arr[], int low, int high) {
    if (low < high) {
        int pi = hoare_partition(arr, low, high);
        quick_sort_hoare(arr, low, pi);
        quick_sort_hoare(arr, pi + 1, high);
    }
}
 
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
}
 
int main() {
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
 
    printf("Original Array:          ");
    print_array(arr1, n);
 
    quick_sort_lomuto(arr1, 0, n - 1);
    printf("Sorted (Lomuto Method):  ");
    print_array(arr1, n);
 
    quick_sort_hoare(arr2, 0, n - 1);
    printf("Sorted (Hoare Method):   ");
    print_array(arr2, n);
 
    return 0;
}
