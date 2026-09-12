#include <stdio.h>

void cofactorMatrix(int a[3][3], int cofactor[3][3])
{
    cofactor[0][0] =  (a[1][1] * a[2][2]) - (a[1][2] * a[2][1]);
    cofactor[0][1] = -(a[1][0] * a[2][2]) + (a[1][2] * a[2][0]);
    cofactor[0][2] =  (a[1][0] * a[2][1]) - (a[1][1] * a[2][0]);

    cofactor[1][0] = -(a[0][1] * a[2][2]) + (a[0][2] * a[2][1]);
    cofactor[1][1] =  (a[0][0] * a[2][2]) - (a[0][2] * a[2][0]);
    cofactor[1][2] = -(a[0][0] * a[2][1]) + (a[0][1] * a[2][0]);

    cofactor[2][0] =  (a[0][1] * a[1][2]) - (a[0][2] * a[1][1]);
    cofactor[2][1] = -(a[0][0] * a[1][2]) + (a[0][2] * a[1][0]);
    cofactor[2][2] =  (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
}

void adjointMatrix(int cofactor[3][3], int adjoint[3][3])
{
    int i, j;

    // Adjoint = transpose of cofactor matrix
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            adjoint[i][j] = cofactor[j][i];
        }
    }
}

void inverseMatrix(int adjoint[3][3], int det)
{
    int i, j;

    printf("\nInverse Matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f\t", (float)adjoint[i][j] / det);
        }
        printf("\n");
    }
}

int main()
{
    int a[3][3];
    int cofactor[3][3];
    int adjoint[3][3];
    int det;
    int i, j;

    printf("Enter elements of 3x3 matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    if (det == 0)
    {
        printf("Inverse does not exist.\n");
    }

    cofactorMatrix(a, cofactor);

    printf("\nCofactor Matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", cofactor[i][j]);
        }
        printf("\n");
    }

    adjointMatrix(cofactor, adjoint);

    printf("\nAdjoint Matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", adjoint[i][j]);
        }
        printf("\n");
    }

    inverseMatrix(adjoint, det);

}