#include <stdio.h>

void input_matrix(int a[3][3])
{
    int i,j;
    int (*p)[3] = a;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", *(p+i)+j);}

void print_matrix(const int c[3][3])
{
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

}

void addMatrix(const int A[3][3], const int B[3][3],int c[3][3])
{
    int i, j;
    int (*p)[3] = A;
    int (*q)[3] = B;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            c[i][j] = *(*(p+i)+j) + *(*(q+i)+j);        
        }
    }
}

int subMatrix(const int A[3][3], const int B[3][3],int c[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            c[i][j] = A[i][j] - B[i][j];
        }
    }

  
}
void mulMatrix(const int A[3][3], const int B[3][3], int c[3][3])
{
    int i, j,k;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++){
        c[i][j] = 0;
            for(k = 0; k < 3; k++){
                c[i][j] = c[i][j] + A[i][k] * B[k][j];
            }
        }
}
}
void transposeMatrix(const int A[3][3], int T[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            T[j][i] = A[i][j]; // row becomes column

        }
    }
}

int isSymmetric(const int A[3][3])
{
    int i, j;
    int sym = 1;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(A[i][j] != A[j][i])
            {
                sym = 0;
            }
        }
    }
    if(sym == 1)
    {
        printf("The matrix is Symmetric\n");
    }
    else
    {
        printf("The matrix is not Symmetric\n");
    }
    return sym;
}
int isSkewSymmetric(const int A[3][3])
{
    int i, j;
    int sym = 1;
    for(i = 0; i < 3; i++)
    {
        if(A[i][i] != 0)
            sym = 0;
        for(j = 0; j < 3; j++)
        {
            if(A[i][j] != -A[j][i])
                sym = 0;
        }
    }
    return sym;
}

int main()
{
    int A[3][3], B[3][3], C[3][3], T[3][3];
    int ch = 0;
    printf("Enter First Matrix:\n");
    input_matrix(A);
    printf("Enter Second Matrix:\n");
    input_matrix(B);
    while(ch != 8){
        printf("\n========== MATRIX KA MENU ==========\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Check Symmetric\n");
        printf("6. Check Skew Symmetric\n");
        printf("7. Display Matrixes\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                addMatrix(A, B, C);
                printf("\nAddition:\n");
                print_matrix(C);
                break;
            case 2:
                subMatrix(A, B, C);
                printf("\nSubtraction:\n");
                print_matrix(C);
                break;
            case 3:
                mulMatrix(A, B, C);
                printf("\nMultiplication:\n");
                print_matrix(C);
                break;
            case 4:
                transposeMatrix(A, T);
                printf("\nTranspose of First Matrix:\n");
                print_matrix(T);
                break;
            case 5:
                isSymmetric(A);
                break;
            case 6:
                if(isSkewSymmetric(A))
                    printf("The matrix is Skew Symmetric.\n");
                else
                    printf("The matrix is not Skew Symmetric.\n");
                break;
            case 7:
                printf("\nFirst Matrix:\n");
                print_matrix(A);
                printf("\nSecond Matrix:\n");
                print_matrix(B);
                break;
            case 8:
                printf("\nProgram Ended.\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    }
}