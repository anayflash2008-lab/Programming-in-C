#include <stdio.h>
int mat[9][10] =
    {
        {0, 0, 0, 5, 0, 0, 0, 0, 0, 12},
        {0, 7, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 9, 0, 0, 0, 4, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 8, 0, 0, 0, 0, 11, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0, 0, 2},
        {0, 1, 0, 0, 0, 0, 0, 0, 13, 0},
        {14, 0, 0, 0, 15, 0, 0, 0, 0, 0}};

void display1()
{
    int i, j;
    printf("Row\tcolumn\tvalue\n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (mat[i][j] != 0)
            {
                printf("%d\t%d\t%d\n", i, j, mat[i][j]);
            }
        }
    }
}
void showmatrix(int option)
{
    int i, j;

    printf("\n%s", option == 1 ? "Row " : option == 2 ? "Col " : "Val ");

    if(option > 3 || option < 1){
        printf("Invalid Option");
    }
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(mat[i][j] != 0)
            {
                printf("%3d ", option == 1 ? i : option == 2 ? j : mat[i][j]);
            }
        }
}
}
void display2()
{
    showmatrix(1);
    showmatrix(2);
    showmatrix(3);
}
int main()
{
    display2();
}