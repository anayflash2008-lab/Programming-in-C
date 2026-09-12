#include <stdio.h>

char board[3][3] =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void display()
{
    int i, j;

    printf("\n");

    for(j = 0; j < 3; j++)
    {
        for(i = 0; i < 3; i++)
        {
            printf(" %c ", board[j][i]);

            if(i < 2)
                printf("|");
        }

        printf("\n");

        if(j < 2)
            printf("---|---|---\n");
    }

    printf("\n");
}

int checkWin()
{
    int i, j;
    int win = 0;

    /* Rows */
    for(j = 0; j < 3; j++)
    {
        if(board[j][0] == board[j][1] &&
           board[j][1] == board[j][2])
            win = 1;
    }

    /* Columns */
    for(i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            win = 1;
    }

    /* Main diagonal */
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        win = 1;

    /* Other diagonal */
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        win = 1;

    return win;
}

int main()
{
    int pos;
    int i, j;
    int moves = 0;
    char player = 'X';
    int winflag = 0;


    while(moves < 9)
    {
        display();

        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &pos);

        if(pos < 1 || pos > 9)
        {
            printf("Invalid position.\n");
            continue;
        }

        j = (pos - 1) / 3;   
        i = (pos - 1) % 3;   

        if(board[j][i] == 'X' ||
           board[j][i] == 'O')
        {
            printf("Position already occupied.\n");
            continue;
        }

        board[j][i] = player;
        moves++;

        if(checkWin())
        {
            //display();
            printf("Player %c wins!\n", player);
            winflag = 1;
            break;
        }
        

        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    display();
    if(winflag == 0){
        printf("Match Draw!\n");
    }

}