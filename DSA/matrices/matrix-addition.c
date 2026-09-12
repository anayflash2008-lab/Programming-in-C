#include <stdio.h>

void input_matrix(int (*A)[3])
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", (*(A + i) + j));
        }
    }
}

void print_matrix(int *C)
{
    int i, j;

    printf("\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", *(C + i * 3 + j));
        }
        printf("\n");
    }
}

void addMatrix(int (*A)[3], int (*B)[3], int *C)
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            *(C + i * 3 + j) = *(*(A + i) + j) + *(*(B + 
                i) + j);
        }
    }
}

void subMatrix(int (*A)[3], int (*B)[3], int *C)
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            *(C + i * 3 + j) = *(*(A + i) + j) - *(*(B + i) + j);
        }
    }
}

void mulMatrix(int (*A)[3], int (*B)[3], int *C)
{
    int i, j, k;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            *(C + i * 3 + j) = 0;

            for(k = 0; k < 3; k++)
            {
                *(C + i * 3 + j) +=
                    (*(*(A + i) + k)) * (*(*(B + k) + j));
            }
        }
    }
}

