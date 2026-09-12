#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i;
    int *arr;
    int sum = 0;
    int max,min;
    float avg;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
     printf("Array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    max = arr[0];
    min = arr[0];
    // Find sum, maximum and minimum from the dynamic array
    for(i = 0; i<n; i++){
        sum = sum + arr[i];
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    // Calculate average and printing everything
    avg = (float)sum / n;
    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);
    printf("\nMaximum = %d", max);
    printf("\nMinimum = %d", min);
    
    // Free memory
    free(arr);
    return 0;
}