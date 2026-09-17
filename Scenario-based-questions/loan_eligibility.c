/* An automated financial portal evaluates loan applications. To qualify for an educational loan:
The applicant’s credit score must be at least 650.
The applicant's annual family income must be greater than ₹3,00,000 OR the applicant must have secured an admission rank ≤1000 in an entrance exam. 
The applicant must not have an existing active loan default (hasDefault == 0).
Questions:
Construct a single C Boolean expression incorporating relational and logical operators to determine eligibility (1 for eligible, 0 for ineligible). 

*/
#include <stdio.h>

int main()
{
    int cs, inc, rank, def, el; // Credit score, Family Income, Admission rank, Active loan default, eligibility criteria(Boolean - 0 or 1)
    printf("Enter credit score: ");
    scanf("%d", &cs);

    printf("Enter family income: ");
    scanf("%d", &inc);

    printf("Enter admission rank: ");
    scanf("%d", &rank);

    printf("Enter active loan default (1 = Yes, 0 = No): ");
    scanf("%d", &def);
    // Eligibility criteria(Considering he has no active loan )
    el = (cs >= 650) &&
               ((inc > 300000) || (rank <= 1000)) &&
               (def == 0);

    printf("Eligibility = %d\n", el);
    // if there is any active loan, the applicant is not eligible for a loan
    if (def == 1)
        printf("Applicant is not eligible due to active loan default.\n");
    else if (el == 1)
        printf("Applicant is eligible for the educational loan.\n");
    else
        printf("Applicant is not eligible for the educational loan.\n");

}