#include <stdio.h>

int main()
{
    int cs, inc, ar, def, el;

    // cs = credit score
    // inc = annual family income
    // ar = admission rank
    // def = active loan default (1 = Yes, 0 = No)
    // el = eligibility (1 = Eligible, 0 = Not Eligible)
    printf("Enter credit score: ");
    scanf("%d", &cs);
    printf("Enter annual family income: ");
    scanf("%d", &inc);
    printf("Enter admission rank: ");
    scanf("%d", &ar);
    printf("Has active loan default? (1 = Yes, 0 = No): ");
    scanf("%d", &def);

    //Checking Eligibility
    el = (cs >= 650) &&
         ((inc > 300000) || (ar <= 1000)) &&
         (def == 0);
    printf("\nEligibility = %d\n", el);
    if (el == 1)
        printf("Applicant is eligible for the educational loan.\n");
    else
        printf("Applicant is not eligible for the educational loan.\n");
}