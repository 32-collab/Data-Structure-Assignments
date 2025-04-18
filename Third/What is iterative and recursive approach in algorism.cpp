#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int key = 7;
    int result = binarySearchIterative(arr, 6, key);
    
    if (result != -1) cout << "Element found at index: " << result;
    else cout << "Element not found.";
    
    return 0;
}
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right) return -1;  // Base case
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == key) return mid;
    else if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, right, key);
    else return binarySearchRecursive(arr, left, mid - 1, key);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int key = 7;
    int result = binarySearchRecursive(arr, 0, 5, key);
    
    if (result != -1) cout << "Element found at index: " << result;
    else cout << "Element not found.";
    
    return 0;
}
