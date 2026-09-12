#include <stdio.h>

void inputMatrix(int matrix[][100], int rows, int cols)
{
    printf("Enter matrix elements:\n");

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][100], int rows, int cols)
{
    printf("\nMatrix:\n");

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int rows, cols;

    printf("Enter rows: ");
    scanf("%d", &rows);

    printf("Enter columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    inputMatrix(matrix, rows, cols);

    displayMatrix(matrix, rows, cols);

    return 0;
}
