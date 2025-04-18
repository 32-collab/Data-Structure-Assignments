#include <iostream>
#include <limits.h> // For INT_MIN

using namespace std;

void findSecondAndThirdLargest(int arr[], int size, int &secondLargest, int &thirdLargest) {
    if (size < 3) {
        cout << "Array should have at least 3 elements." << endl;
        return;
    }

    int largest = INT_MIN;
    secondLargest = INT_MIN;
    thirdLargest = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        } else if (arr[i] > thirdLargest && arr[i] != secondLargest) {
            thirdLargest = arr[i];
        }
    }

    cout << "Second Largest: " << secondLargest << endl;
    cout << "Third Largest: " << thirdLargest << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int secondLargest, thirdLargest;
    
    findSecondAndThirdLargest(arr, size, secondLargest, thirdLargest);

    return 0;
}
