#include <stdio.h>

int main()
{
    int real[3][3], imag[3][3];
    int i, j, flag = 1;

    printf("Enter real parts:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &real[i][j]);
        }
    }

    printf("Enter imaginary parts:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &imag[i][j]);
        }
    }

    // Print the matrix 
    printf("\nMatrix:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(imag[i][j] >= 0)
                printf("%d+%di\t", real[i][j], imag[i][j]);
            else
                printf("%d%di\t", real[i][j], imag[i][j]);
        }
        printf("\n");
    }

    // Check Hermitian property 
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(real[i][j] != real[j][i] ||
               imag[i][j] != -imag[j][i])
            {
                flag = 0;
                break;
            }
        }

        if(flag == 0)
            break;
    }

    if(flag)
        printf("\nMatrix is Hermitian.\n");
    else
        printf("\nMatrix is not Hermitian.\n");

}