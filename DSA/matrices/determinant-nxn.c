#include <stdio.h>
#define MAX 10

void input_matrix(int A[][MAX], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

void print_matrix(int A[][MAX], int n)
{
    int i, j;

    printf("\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }

        printf("\n");
    }
}

int nxndet(int A[][MAX], int n)
{
    int M[MAX][MAX];
    int det = 0;
    int sign = 1;
    int j;

    if(n == 1)
    {
        return A[0][0];
    }

    if(n == 2)
    {
        return A[0][0] * A[1][1]
             - A[0][1] * A[1][0];
    }

    for(j = 0; j < n; j++)
    {
        int x, y;
        int r = 0, c = 0;

        for(x = 1; x < n; x++)
        {
            for(y = 0; y < n; y++)
            {
                if(y != j)
                {
                    M[r][c] = A[x][y];

                    c++;

                    if(c == n - 1)
                    {
                        c = 0;
                        r++;
                    }
                }
            }
        }

        det += sign * A[0][j] * nxndet(M, n - 1);

        sign = -sign;
    }

    return det;
}

int main()
{
    int A[MAX][MAX];
    int n;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid order!\n");
        return 1;
    }

    printf("\nEnter Matrix:\n");
    input_matrix(A, n);

    printf("\nMatrix:");
    print_matrix(A, n);

    printf("\nDeterminant = %d\n", nxndet(A, n));

}