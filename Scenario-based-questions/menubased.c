/*You are programming the user interface for an Automated Teller Machine (ATM) that performs banking operations. Upon inserting a card, the user is presented with the following options: 
Deposit
Withdraw
Check Balance
Exit 

Questions:
Write a structured C program using a switch statement that prompts the user for their choice and processes the selected transaction. 
Implement safe balance validation under option 2 (Withdraw) to reject requests exceeding the current account balance.
Ensure improper inputs (e.g., entering 5 or -1) are handled appropriately using the default label. 
*/
#include <stdio.h>

int main()
{
    int ch;
    float bal = 5000, amt;

    printf("===== ATM MENU =====\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");

    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            printf("Enter amount: ");
            scanf("%f", &amt);

            if (amt > 0)
            {
                bal = bal + amt;
                printf("Deposit successful.\n");
                printf("Balance = %.2f\n", bal);
            }
            else
            {
                printf("Invalid amount.\n");
            }
            break;

        case 2:
            printf("Enter amount: ");
            scanf("%f", &amt);

            if (amt <= 0)
            {
                printf("Invalid amount.\n");
            }
            else if (amt > bal)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                bal = bal - amt;
                printf("Withdrawal successful.\n");
                printf("Balance = %.2f\n", bal);
            }
            break;

        case 3:
            printf("Balance = %.2f\n", bal);
            break;

        case 4:
            printf("Thank you for using the ATM.\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}