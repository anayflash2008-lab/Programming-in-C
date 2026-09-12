#include <stdio.h>
#include <stdlib.h>

struct Book
{
    int id;
    char name[100];
    char author[100];
    int qty;
};


void addBook()
{
    FILE *fp;
    struct Book b;
    int i;

    fp = fopen("Library.dat", "ab");

    if (fp == NULL)
    {
        printf("Error Opening File!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    getchar();

    printf("Enter Book Name: ");
    fgets(b.name, 100, stdin);

    i = 0;
    while (b.name[i] != '\0')
    {
        if (b.name[i] == '\n')
        {
            b.name[i] = '\0';
            break;
        }
        i++;
    }

    printf("Enter Author Name: ");
    fgets(b.author, 100, stdin);

    i = 0;
    while (b.author[i] != '\0')
    {
        if (b.author[i] == '\n')
        {
            b.author[i] = '\0';
            break;
        }
        i++;
    }

    printf("Enter Quantity: ");
    scanf("%d", &b.qty);

    fwrite(&b, sizeof(struct Book), 1, fp);

    fclose(fp);

    printf("\nBook Added Successfully!\n");
}


void displayBooks()
{
    FILE *fp;
    struct Book b;

    fp = fopen("Library.dat", "rb");

    if (fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------------\n");
    printf("%-10s %-30s %-20s %-5s\n", "ID", "Book Name", "Author", "Qty");
    printf("-----------------------------------------------------------------------------\n");

    while (fread(&b, sizeof(struct Book), 1, fp))
    {
        printf("%-10d %-30s %-20s %-5d\n",
               b.id,
               b.name,
               b.author,
               b.qty);
    }

    fclose(fp);
}

void searchBook()
{
    FILE *fp;
    struct Book b;

    int id;
    int found = 0;

    fp = fopen("Library.dat", "rb");

    if (fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct Book), 1, fp))
    {
        if (b.id == id)
        {
            printf("\nBook Found!\n");
            printf("ID : %d\n", b.id);
            printf("Name : %s", b.name);
            printf("Author : %s", b.author);
            printf("Quantity : %d\n", b.qty);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found == 0)
    {
        printf("Book Not Found!\n");
    }
}

void issueBook()
{
    FILE *fp, *temp;
    struct Book b;

    int id;
    int found = 0;

    fp = fopen("Library.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct Book), 1, fp))
    {
        if (b.id == id)
        {
            found = 1;

            if (b.qty > 0)
            {
                b.qty--;
                printf("Book Issued Successfully!\n");
            }
            else
            {
                printf("Book Out Of Stock!\n");
            }
        }

        fwrite(&b, sizeof(struct Book), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("Library.dat");
    rename("temp.dat", "Library.dat");

    if (found == 0)
    {
        printf("Book Not Found!\n");
    }
}

void returnBook()
{
    FILE *fp, *temp;
    struct Book b;

    int id;
    int found = 0;

    fp = fopen("Library.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct Book), 1, fp))
    {
        if (b.id == id)
        {
            b.qty++;
            found = 1;
        }

        fwrite(&b, sizeof(struct Book), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("Library.dat");
    rename("temp.dat", "Library.dat");

    if (found)
    {
        printf("Book Returned Successfully!\n");
    }
    else
    {
        printf("Book Not Found!\n");
    }
}

void deleteBook()
{
    FILE *fp, *temp;
    struct Book b;

    int id;
    int found = 0;

    fp = fopen("Library.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct Book), 1, fp))
    {
        if (b.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&b, sizeof(struct Book), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("Library.dat");
    rename("temp.dat", "Library.dat");

    if (found)
    {
        printf("Book Deleted Successfully!\n");
    }
    else
    {
        printf("Book Not Found!\n");
    }
}


int main()
{
    int ch;

    while (1)
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            deleteBook();
            break;

        case 7:
            printf("Thank You!\n");
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

}