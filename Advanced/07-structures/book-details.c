#include <stdio.h>

struct Book
{
    char id;
    char name[20];
    float price;
};

int main()
{
    struct Book book[3];
    int i, max = 0;

    for(i = 0; i < 3; i++)
    {
        printf("\nEnter details of Book %d\n", i + 1);

        printf("ID: ");
        scanf("%s", &book[i].id);

        printf("Name: ");
        scanf("%s", book[i].name);

        printf("Price: ");
        scanf("%f", &book[i].price);
    }

    printf("\n------------ Book Details -------------\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("ID: %d\n", book[i].id);
        printf("Name: %s\n", book[i].name);
        printf("Price: %.2f\n", book[i].price);
    }

    for(i = 1; i < 3; i++)
    {
        if(book[i].price > book[max].price)
        {
            max = i;
        }
    }

    printf("\n--- Most Expensive Book ---\n");
    printf("ID: %d\n", book[max].id);
    printf("Name: %s\n", book[max].name);
    printf("Price: %.2f\n", book[max].price);

    return 0;
}