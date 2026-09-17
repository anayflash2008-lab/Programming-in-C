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