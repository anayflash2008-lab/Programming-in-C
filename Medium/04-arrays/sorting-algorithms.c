#include <stdio.h>

int MAX = 10;

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void linearSearch(int arr[], int n, int key)
{
    int i;
    int found = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at Position %d\n", i+1);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Element not found.\n");
    }
}

void binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int pos = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            pos = mid + 1;
            break;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (pos != 0)
    {
        printf("Element found at Position %d\n", pos);
    }
    else
    {
        printf("Element not found.\n");
    }
}

void display(int arr[], int n)
{
    int i;
    printf("\nArray: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX];
    int n, ch, key, result;
    int i;
    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nChoose an operation:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Linear Search\n");
    printf("5. Binary Search\n");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
            bubbleSort(arr, n);
            printf("\nBubble Sort selected.\n");
            display(arr, n);
            break;

        case 2:
            selectionSort(arr, n);
            printf("\nSelection Sort selected.\n");
            display(arr, n);
            break;

        case 3:
            insertionSort(arr, n);
            printf("\nInsertion Sort selected.\n");
            display(arr, n);
            break;

        case 4:
            printf("\nEnter element to search: ");
            scanf("%d", &key);
            linearSearch(arr, n, key);
            break;

            case 5:
                printf("\nEnter element to search: ");
                scanf("%d", &key);
                bubbleSort(arr, n);
                printf("\nSorted array:");
                display(arr, n);
                binarySearch(arr, n, key);
                break;

        default:
            printf("\nInvalid choice.\n");
    }
}