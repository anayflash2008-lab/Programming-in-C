#include <stdio.h>

void search(int ar[], int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(ar[i] == key)
        {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found\n");
}


int main()
{
    int ar[5] = {100, 550, 20, 30, 10};
    int key,i;
    printf("Enter element to search: ");
    scanf("%d", &key);
    search(ar, 5, key);
}