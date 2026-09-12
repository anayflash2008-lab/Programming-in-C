#include <stdio.h>

int isLeapYear(int year)
{
    int leap = 0;
    //leap century
    if(year % 400 == 0)
        leap = 1;
    //leap year
    else if(year % 100 == 0)
        leap = 0;
    else if(year % 4 == 0)
        leap = 1;
    else
        leap = 0;

    return leap;
}

int daysInMonth(int month, int year)
{
    int days = 0;
    // each case for every month
    switch(month)
    {
        case 1:
            days = 31;
            break;

        case 2:
            if(isLeapYear(year))
                days = 29;
            else
                days = 28;
            break;

        case 3:
            days = 31;
            break;

        case 4:
            days = 30;
            break;

        case 5:
            days = 31;
            break;

        case 6:
            days = 30;
            break;

        case 7:
            days = 31;
            break;

        case 8:
            days = 31;
            break;

        case 9:
            days = 30;
            break;

        case 10:
            days = 31;
            break;

        case 11:
            days = 30;
            break;

        case 12:
            days = 31;
            break;
    }

    return days;
}

int firstDayOfMonth(int month, int year)
{
    int days = 1;
    int i;
    int day;

    // Count complete years
    for(i = 1900; i < year; i++)
    {
        if(isLeapYear(i))
            days += 366;
        else
            days += 365;
    }

    // Count complete months of the current year
    for(i = 1; i < month; i++)
    {
        days += daysInMonth(i, year);
    }

    day = days % 7;

    // If remainder is 0, it is Sunday
    if(day == 0)
        day = 7;

    return day;
}

void printMonthName(int month)
{
    switch(month)
    {
        case 1: 
        printf("January"); 
        break;
        case 2: 
        printf("February"); 
        break;
        case 3: 
        printf("March"); 
        break;
        case 4: 
        printf("April");
        break;
        case 5: 
        printf("May"); 
        break;
        case 6: 
        printf("June"); 
        break;
        case 7: 
        printf("July"); 
        break;
        case 8: 
        printf("August"); 
        break;
        case 9: 
        printf("September"); 
        break;
        case 10: 
        printf("October"); 
        break;
        case 11: 
        printf("November"); 
        break;
        case 12: 
        printf("December"); 
        break;
    }

}

void printCalendar(int month, int year)
{
    int firstDay;
    int totalDays;
    int i;

    firstDay = firstDayOfMonth(month, year);

    // Convert 1=Mon,...,7=Sun into 0=Sun,...,6=Sat
    firstDay = firstDay % 7;

    totalDays = daysInMonth(month, year);

    printf("\n\n\t");
    printMonthName(month);
    printf(" %d\n\n", year);

    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Print blank spaces before the first date 
    for(i = 0; i < firstDay; i++)
        printf("    ");

    // Print all dates 
    for(i = 1; i <= totalDays; i++)
    {
        printf("%3d ", i);

        // Move to next line after Saturday 
        if((i + firstDay) % 7 == 0)
            printf("\n");
    }

    printf("\n");
}
void printWholeYear(int year)
{
    int i;

    for(i = 1; i <= 12; i++)
    {
        printCalendar(i, year);
        printf("\n");
    }
}

void checkLeapYear(int year)
{
    if(isLeapYear(year))
        printf("\n%d is a Leap Year.\n", year);
    else
        printf("\n%d is not a Leap Year.\n", year);
}

int main(){
   /* printf("%d", firstDayOfMonth(8, 2026));


    int month, year;

    printf("Enter Month : ");
    scanf("%d", &month);

    printf("Enter Year: ");
    scanf("%d", &year);

    printCalendar(month, year); */


    int ch;
    int month;
    int year;

    while(ch != 4)
        {
            printf("\n===== CALENDAR MENU =====\n");
            printf("1. Print Calendar of a Month\n");
            printf("2. Print Whole Year Calendar\n");
            printf("3. Check Leap Year\n");
            printf("4. Exit\n");

            printf("\nEnter Choice: ");
            scanf("%d", &ch);

            switch(ch)
            {
                case 1:
                    printf("Enter Month: ");
                    scanf("%d", &month);

                    printf("Enter Year: ");
                    scanf("%d", &year);

                    printCalendar(month, year);
                    break;

                case 2:
                    printf("Enter Year: ");
                    scanf("%d", &year);

                    printWholeYear(year);
                    break;

                case 3:
                    printf("Enter Year: ");
                    scanf("%d", &year);

                    checkLeapYear(year);
                    break;

                case 4:
                    printf("Exiting...\n");
                    break;

                default:
                    printf("Invalid Choice!\n");
            }
        }

}

