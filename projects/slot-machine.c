#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("\n===== SLOT MACHINE =====\n");
    printf("1. Play\n");
    printf("2. View Statistics\n");
    printf("3. View Payout Table\n");
    printf("4. Reset Game\n");
    printf("5. Quit\n");
}
void payoutTable()
{
    printf("\n===== PAYOUT TABLE =====\n");

    printf("777 -> 20x Bet\n");
    printf("$$$ -> 15x Bet + Free Spin\n");
    printf("AAA -> 10x Bet\n");
    printf("BBB -> 8x Bet\n");
    printf("CCC -> 6x Bet\n");
    printf("DDD -> 5x Bet\n");
    printf("Any Pair -> 2x Bet\n");
    printf("No Match -> Lose Bet\n");
}
void display(char r1,
             char r2,
             char r3)
{
    printf("-----------------\n");
    printf("| %c | %c | %c |\n",
           r1, r2, r3);
    printf("-----------------\n");
}
char spin(int lucky)
{
    int x;
    char sym;

    x = rand() % 100;

    if(lucky)
    {
        if(x < 20)
            sym = 'A';
        else if(x < 40)
            sym = 'B';
        else if(x < 58)
            sym = 'C';
        else if(x < 70)
            sym = 'D';
        else if(x < 85)
            sym = '$';
        else
            sym = '7';
    }
    else
    {
        if(x < 25)
            sym = 'A';
        else if(x < 47)
            sym = 'B';
        else if(x < 65)
            sym = 'C';
        else if(x < 80)
            sym = 'D';
        else if(x < 92)
            sym = '$';
        else
            sym = '7';
    }

    return sym;
}
int payout(char r1,
           char r2,
           char r3,
           int bet,
           int *freeSpin)
{
    int won = 0;

    if(r1 == r2 && r2 == r3)
    {
        if(r1 == '7')
        {
            printf("JACKPOT!!!\n");
            won = bet * 20;
        }
        else if(r1 == '$')
        {
            printf("WON A FREE SPIN!\n");
            *freeSpin = 1;
            won = bet * 15;
        }
        else if(r1 == 'A')
            won = bet * 10;

        else if(r1 == 'B')
            won = bet * 8;

        else if(r1 == 'C')
            won = bet * 6;

        else if(r1 == 'D')
            won = bet * 5;
    }
    else if(r1 == r2 ||
            r2 == r3 ||
            r1 == r3)
    {
        printf("PAIR!\n");
        won = bet * 2;
    }

    return won;
}
void statistics(int money,
                int highest,
                int spins,
                int wins,
                int losses,
                int totalWon,
                int totalLost)
{
    printf("\n===== STATISTICS =====\n");

    printf("Balance          : ₹%d\n", money);
    printf("Highest Balance  : ₹%d\n", highest);
    printf("Total Spins      : %d\n", spins);
    printf("Wins             : %d\n", wins);
    printf("Losses           : %d\n", losses);
    printf("Total Won        : ₹%d\n", totalWon);
    printf("Total Lost       : ₹%d\n", totalLost);

    if(spins != 0)
        printf("Win Rate         : %.2f%%\n",
               (wins * 100.0) / spins);
}
