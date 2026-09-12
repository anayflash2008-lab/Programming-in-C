#include <stdio.h>
#include <stdlib.h>
// Global Variables
    int money = 1000;
    int highest = 1000;
    int spins = 0;
    int wins = 0;
    int losses = 0;
    int totalWon = 0;
    int totalLost = 0;
    int ch = 0;
    int bet;
    int won;
    int lucky;
    int freeSpin = 0;
void initialize()
{
    money = 1000;
    highest = 1000;
    spins = 0;
    wins = 0;
    losses = 0;
    totalWon = 0;
    totalLost = 0;
    ch = 0;
    bet = 0;
    won = 0;
    lucky = 0;
    freeSpin = 0;
}

void menu()
{
    printf("\n========= SLOT MACHINE =========\n");
    printf("1. Play\n");
    printf("2. View Statistics\n");
    printf("3. View Payout Table\n");
    printf("4. Reset Game\n");
    printf("5. Quit\n");
}
void payoutTable()
{
    printf("\n========= PAYOUT TABLE =========\n");

    printf("777 -> 20x Bet\n");
    printf("$$$ -> 15x Bet + Free Spin\n");
    printf("AAA -> 10x Bet\n");
    printf("BBB -> 8x Bet\n");
    printf("CCC -> 6x Bet\n");
    printf("DDD -> 5x Bet\n");
    printf("Any Pair -> 2x Bet\n");
    printf("No Match -> Lose Bet\n");
}
void display(char r1, char r2, char r3)
{
    printf("-----------------\n");
    printf("| %c | %c | %c |\n", r1, r2, r3);
    printf("-----------------\n");
}
int spin(int lucky){
    int x;
    int sym;

    x = rand() % 100; //chooses a number from 0 to 99 

    if(lucky){
        if(x < 20)
            sym = 'A';
        else if(x < 40)
            sym = 'B';
        else if(x < 60)
            sym = 'C';
        else if(x < 75)
            sym = 'D';
        else if(x < 92)
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
           int bet)
{
    int wonamt = 0;

    if(r1 == r2 && r2 == r3)
    {
        if(r1 == '7')
        {
            printf("JACKPOT!\n");
            wonamt = bet * 20;
        }

        else if(r1 == '$')
        {
            printf("FREE SPIN WON!\n");
            freeSpin = 1;
            wonamt = bet * 15;
        }

        else if(r1 == 'A')
            wonamt = bet * 10;

        else if(r1 == 'B')
            wonamt = bet * 8;

        else if(r1 == 'C')
            wonamt = bet * 6;

        else if(r1 == 'D')
            wonamt = bet * 5;
    }

    else if(r1 == r2 || r1 == r3 || r2 == r3)
    {
        printf("PAIR!\n");
        wonamt = bet * 2;
    }

    return wonamt;
}
void statistics()
{
    printf("\n===== STATISTICS =====\n");

    printf("Balance          : %drs\n", money);
    printf("Highest Balance  : %drs\n", highest);
    printf("Total Spins      : %d\n", spins);
    printf("Wins             : %d\n", wins);
    printf("Losses           : %d\n", losses);
    printf("Total Won        : %drs\n", totalWon);
    printf("Total Lost       : %drs\n", totalLost);

    if(spins != 0)
        printf("Win Rate         : %.2f%%\n",
               (wins * 100.0) / spins);
}

int main()
{
    char r1, r2, r3;
    initialize();


    while(ch != 5)
    {
        if(money == 0){
            printf("\nUr out of Money!!\n");
            ch = 5;
            break;
        }
        menu();
        printf("Enter Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                payoutTable();
            
                if(money < 0 || money == 0)
                {
                    money = 0;
                    printf("\nBANKRUPTCY!\n");
                    ch = 5;
                    break;
                }

                printf("\nBalance : %d\n", money);

                printf("Enter Bet : ");
                scanf("%d", &bet);

                if(bet <= 0 || bet > money)
                {
                    printf("Invalid Bet!\n");
                    break;
                }

                if(freeSpin == 0)
                {
                    money = money -  bet;
                }
                else
                {
                    printf("FREE SPIN USED!\n");
                    freeSpin = 0;
                }

                spins++;

                lucky = (spins % 10 == 0);

                char r1 = spin(lucky);
                char r2 = spin(lucky);
                char r3 = spin(lucky);

                display(r1, r2, r3);

                won = payout(r1, r2, r3, bet);

                if(won > 0)
                {
                    wins++;
                    money = money + won;
                    totalWon = totalWon + won;

                    printf("You Won %d!\n", won);
                }
                else
                {
                    losses++;
                    totalLost += losses + bet;

                    printf("Better Luck Next Time!\n");
                }

                if(money > highest)
                    highest = money;

                printf("Current Balance : %d\n", money);
            
            case 2:
                statistics();
                break;
            
            case 3:
                payoutTable();
                break;
            case 4:
                initialize();
                printf("Game Reset Successfully!\n");
                break;
            case 5:
                printf("Thanks For Playing!\n");
                break;
}}}