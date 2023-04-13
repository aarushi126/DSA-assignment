#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[i] < arr[l]) {
        largest = l;
    }
 
    if (r < n && arr[largest] < arr[r]) {
        largest = r;
    }
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[15] = {10, 6, 12, 8, 3, 9, 1, 14, 2, 13, 5, 7, 15, 11, 4};

    // Before heapifying
    cout << "Before heapifying: ";
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Convert the array into a heap using Floyd's algorithm
    heapSort(arr, 15);

    // After heapifying
    cout << "After heapifying: ";
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array in descending order using Heap Sort
    heapSort(arr, 15);
    reverse(arr, arr + 15);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
