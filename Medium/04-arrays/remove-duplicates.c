#include <stdio.h>

int main()
{
    int arr[100], n, i, j, flag;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Array before removing duplicates: ");
    for(i = 0; i < n; i++)
    printf("%d ", arr[i]);

    printf("\nArray after removing duplicates: ");

    for(i = 0; i < n; i++)
    {
        flag = 0;

        for(j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            printf("%d ", arr[i]);
        
        
    }
}