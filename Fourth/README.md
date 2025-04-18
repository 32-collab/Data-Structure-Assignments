#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm> // For std::copy

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
}

// Selection Sort
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) < *(arr + minIndex)) {
                minIndex = j;
            }
        }
        swap((arr + minIndex), (arr + i));
    }
}

// Quick Sort
int partition(int* arr, int low, int high) {
    int pivot = *(arr + high);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (*(arr + j) < pivot) {
            i++;
            swap((arr + i), (arr + j));
        }
    }
    swap((arr + i + 1), (arr + high));
    return i + 1;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to measure execution time
void evaluateSorting(int* arr, int n, void (*sortFunc)(int*, int)) {
    int* tempArr = new int[n];
    std::copy(arr, arr + n, tempArr);

    clock_t start = clock();
    sortFunc(tempArr, n);
    clock_t end = clock();
    
    std::cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    delete[] tempArr;
}

int main() {
    int n = 1000;
    int* arr = new int[n];

    // Initialize array with random values
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 10000;
    }

    std::cout << "Bubble Sort:\n";
    evaluateSorting(arr, n, bubbleSort);

    std::cout << "Selection Sort:\n";
    evaluateSorting(arr, n, selectionSort);

    std::cout << "Quick Sort:\n";
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    std::cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    delete[] arr;
    return 0;
}
