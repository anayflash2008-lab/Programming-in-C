#include <stdio.h>

int main()
{
    int n, i, j, arr[100], lead;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Leaders are: ");

    for(i = 0; i < n; i++)
    {
        lead = 1;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] >= arr[i])
            {
                lead = 0;
                break;
            }
        }

        if(lead == 1){
            printf("%d ", arr[i]);
            
        }   
}   
}