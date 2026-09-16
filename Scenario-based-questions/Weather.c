#include <stdio.h>

int main()
{
    float at;
    char wt;
    unsigned int art;

    printf("Enter ambient temperature (-40.0 to 85.0 C): ");
    scanf("%f", &at);

    printf("Enter wind direction (N/S/E/W): ");
    scanf(" %c", &wt);

    printf("Enter accumulated rain ticks (0 to 60000): ");
    scanf("%u", &art);

    // Checking Ambient Temperature
    if (at >= -40.0 && at <= 85.0)
    {
        printf("Ambient temperature is within the valid range.\n");
    }
    else
    {
        printf("Ambient temperature is out of range.\n");
    }

    // Checking Wind Direction
    if (wt == 'N' || wt == 'S' || wt == 'E' || wt == 'W')
    {
        printf("Wind direction is valid.\n");
    }
    else
    {
        printf("Wind direction is invalid.\n");
    }

    // Checking Accumulated Rain Ticks
    if (art <= 60000)
    {
        printf("Accumulated rain ticks are within the valid range.\n");
    }
    else
    {
        printf("Accumulated rain ticks are out of range.\n");
    }

    return 0;
}