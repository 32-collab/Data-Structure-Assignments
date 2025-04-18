#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;

    // Input three numbers
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    // Find the smallest number
    int smallest = num1;

    if (num2 < smallest) {
        smallest = num2;
    }
    if (num3 < smallest) {
        smallest = num3;
    }

    // Output the smallest number
    cout << "The smallest number is: " << smallest << endl;

    return 0;
}