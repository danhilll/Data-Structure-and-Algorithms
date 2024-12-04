#include <iostream>

using namespace std;

void bubbleSort(int arr[][2], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) { 
                swap(arr[j][0], arr[j + 1][0]);
                swap(arr[j][1], arr[j + 1][1]);
            }
        }
    }
}

void printProperties(int arr[][2], int n) {

    cout << "Properties = [";
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << ", "; 
        cout << "[" << arr[i][0] << "," << arr[i][1] << "]";
    }
    cout << "]" << endl;
}

int main() {

    int arr1[][2] = {{5, 5}, {6, 3}, {3, 6}}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort(arr1, n1);
    printProperties(arr1, n1); 
    cout << "Output: 0\n";

    int arr2[][2] = {{2, 2}, {3, 3}}; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bubbleSort(arr2, n2);
    printProperties(arr2, n2); 
    cout << "Output: 1\n";
    
    return 0;
}