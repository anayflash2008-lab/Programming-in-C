#include <stdio.h>
#include "matrix-addition.c"

int det2(int (*a)[2])
{
    return *(*(a + 0) + 0) * *(*(a + 1) + 1)
         - *(*(a + 0) + 1) * *(*(a + 1) + 0);
}

void print_minor(int *M)
{
    int i, j;

    printf("\nMinor Matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d ", *(M + i * 2 + j));
        }

        printf("\n");
    }
}

int minor(int (*A)[3], int i, int j)
{
    int M[2][2];
    int x, y;
    int r = 0, c = 0;

    for(x = 0; x < 3; x++)
    {
        for(y = 0; y < 3; y++)
        {
            if(x != i && y != j)
            {
                *(*(M + r) + c) = *(*(A + x) + y);

                c++;

                if(c == 2)
                {
                    c = 0;
                    r++;
                }
            }
        }
    }

    return det2(M);
}

int det3(int (*A)[3])
{
    int j;
    int det = 0;
    int sign = 1;

    for(j = 0; j < 3; j++)
    {
        det = det + sign * (*(*(A + 0) + j)) * minor(A, 0, j);

        sign = -sign;
    }

    return det;
}

/*int main()
{
    int A[3][3];

    printf("Enter Matrix:\n");
    input_matrix(A);

    printf("\nDeterminant = %d\n", det3(A));

    
}*/