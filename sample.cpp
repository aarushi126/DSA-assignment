#include <iostream>
using namespace std;

// function to swap two values
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// function to heapify the array
void heapify(int arr[], int n, int i) {
    int largest = i; // initialize largest as root
    int l = 2*i + 1; // left child index
    int r = 2*i + 2; // right child index

    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // if largest is not root
    if (largest != i) {
        // swap the values
        swap(arr[i], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// function to perform heap sort
void heapSort(int arr[], int n) {
    // build heap (rearrange array)
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // one by one extract an element from heap
    for (int i = n-1; i >= 0; i--) {
        // move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    // create the array
    int arr[] = {10, 6, 12, 8, 3, 9, 1, 14, 2, 13, 5, 7, 15, 11, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // print the array before making a heap
    cout << "Array before making a heap: ";
    printArray(arr, n);

    // convert the array into a heap using Floyd's algorithm
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // print the array after making a heap
    cout << "Array after making a heap: ";
    printArray(arr, n);

    // sort the array in descending order using heap sort
    heapSort(arr, n);

    // print the array after sorting
    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}
