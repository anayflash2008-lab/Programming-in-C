#include <stdio.h>

#define MAX_EXP 100

typedef struct
{
    char cat[20];
    float amt;
    int d, m, y;
} Expense;

Expense exp[MAX_EXP];
int cnt = 0;

void cpyStr(char des[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
}

int cmpStr(char a[], char b[])
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return 0;
        i++;
    }

    return (a[i] == '\0' && b[i] == '\0');
}

void addExp()
{
    if (cnt >= MAX_EXP)
    {
        printf("\nExpense List Full!\n");
        return;
    }

    printf("\nEnter Amount: ");
    scanf("%f", &exp[cnt].amt);

    printf("Enter Category: ");
    scanf("%s", exp[cnt].cat);

    printf("Enter Date (DD MM YYYY): ");
    scanf("%d%d%d", &exp[cnt].d, &exp[cnt].m, &exp[cnt].y);

    cnt++;

    printf("\nExpense Added Successfully!\n");
}

void dispExp()
{
    if (cnt == 0)
    {
        printf("\nNo Expenses Found!\n");
        return;
    }

    printf("\n---------------------------------------\n");
    printf("          ALL EXPENSES\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < cnt; i++)
    {
        printf("%d. $%.2f | %s | %02d/%02d/%d\n",
               i + 1,
               exp[i].amt,
               exp[i].cat,
               exp[i].d,
               exp[i].m,
               exp[i].y);
    }
}

void monRpt()
{
    int m, y;
    float tot = 0;

    printf("\nEnter Month and Year: ");
    scanf("%d%d", &m, &y);

    printf("\nExpenses for %02d/%d\n\n", m, y);

    for (int i = 0; i < cnt; i++)
    {
        if (exp[i].m == m && exp[i].y == y)
        {
            printf("$%.2f | %s | %02d/%02d/%d\n",
                   exp[i].amt,
                   exp[i].cat,
                   exp[i].d,
                   exp[i].m,
                   exp[i].y);

            tot += exp[i].amt;
        }
    }

    printf("\nTotal Spending = $%.2f\n", tot);
}

void highCat()
{
    if (cnt == 0)
    {
        printf("\nNo Expenses Found!\n");
        return;
    }

    char cats[50][20];
    float tot[50];
    int catCnt = 0;

    for (int i = 0; i < cnt; i++)
    {
        int f = -1;

        for (int j = 0; j < catCnt; j++)
        {
            if (cmpStr(cats[j], exp[i].cat))
            {
                f = j;
                break;
            }
        }

        if (f == -1)
        {
            cpyStr(cats[catCnt], exp[i].cat);
            tot[catCnt] = exp[i].amt;
            catCnt++;
        }
        else
        {
            tot[f] += exp[i].amt;
        }
    }

    int mx = 0;

    for (int i = 1; i < catCnt; i++)
    {
        if (tot[i] > tot[mx])
            mx = i;
    }

    printf("\nHighest Spending Category\n");
    printf("Category : %s\n", cats[mx]);
    printf("Amount   : $%.2f\n", tot[mx]);
}

int main()
{
    int ch;

    do
    {
        printf("\n========== EXPENSE TRACKER ==========\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Monthly Report\n");
        printf("4. Highest Spending Category\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &ch);

switch (choice)
        {
        case 1:
            addExpense();
            break;

        case 2:
            displayExpenses();
            break;

        case 3:
            monthlyReport();
            break;

        case 4:
            highestCategory();
            break;

        case 5:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}