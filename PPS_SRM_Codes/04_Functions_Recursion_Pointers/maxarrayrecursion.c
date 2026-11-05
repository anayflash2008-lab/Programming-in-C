#include <stdio.h>

// Recursive function to find the maximum element
int findMax(int arr[], int n) {
    // Base case: If there is only one element left, return it
    if (n == 1) {
        return arr[0];
    }
    // Recursive call: Find the maximum in the rest of the array
    int maxOfRest = findMax(arr, n - 1);
    // Compare the last element with the maximum of the rest
    if (arr[n - 1] > maxOfRest)
        return arr[n - 1];
    else
        return maxOfRest;
}

int main() {
    int arr[] = {12, 45, 7, 91, 23, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = findMax(arr, n);
    printf("The maximum element in the array is: %d\n", max);
    return 0;
}
