#include <stdio.h>

int main()
{
    int cs, inc, rank, def, el;
    printf("Enter credit score: ");
    scanf("%d", &cs);

    printf("Enter family income: ");
    scanf("%d", &inc);

    printf("Enter admission rank: ");
    scanf("%d", &rank);

    printf("Enter active loan default (1 = Yes, 0 = No): ");
    scanf("%d", &def);

    el = (cs >= 650) &&
               ((inc > 300000) || (rank <= 1000)) &&
               (def == 0);

    printf("Eligibility = %d\n", el);

    if (def == 1)
        printf("Applicant is not eligible due to active loan default.\n");
    else if (el == 1)
        printf("Applicant is eligible for the educational loan.\n");
    else
        printf("Applicant is not eligible for the educational loan.\n");

}