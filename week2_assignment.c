/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 2: Formulas and Conditions
 */
#include <stdio.h>
#include <math.h>

/* ===== bank_loan.c ===== */
/* bank_loan.c - Loan eligibility: age >= 21 and annual income >= 21,000 */

void task_bank_loan(void)
{
    int age;
    double income;

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your annual income (KSh): ");
    scanf("%lf", &income);

    if (age >= 21 && income >= 21000)
        printf("Congratulations you qualify for a loan.\n");
    else
        printf("Unfortunately, we are unable to offer you a loan at this time.\n");
}

/* ===== compound_interest.c ===== */
/* compound_interest.c - CI = P(1 + r/100)^t - P   (compile with -lm) */

void task_compound_interest(void)
{
    double principal, time, rate, amount, ci;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the time (years): ");
    scanf("%lf", &time);
    printf("Enter the rate (%%): ");
    scanf("%lf", &rate);

    amount = principal * pow(1 + rate / 100, time);
    ci = amount - principal;

    printf("Total amount      = %.2f\n", amount);
    printf("Compound interest = %.2f\n", ci);
}

/* ===== cylinder.c ===== */
/* cylinder.c - Volume and surface area of a cylinder */

#define PI 3.14159265358979

void task_cylinder(void)
{
    double r, h, volume, surface;

    printf("Enter the radius of the cylinder: ");
    scanf("%lf", &r);
    printf("Enter the height of the cylinder: ");
    scanf("%lf", &h);

    volume  = PI * r * r * h;                  /* V = pi r^2 h */
    surface = 2 * PI * r * r + 2 * PI * r * h; /* A = 2 pi r^2 + 2 pi r h */

    printf("Volume       = %.2f\n", volume);
    printf("Surface area = %.2f\n", surface);
}

/* ===== simple_interest.c ===== */
/* simple_interest.c - SI = (principal * time * rate) / 100 */

void task_simple_interest(void)
{
    double principal, time, rate, si;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the time (years): ");
    scanf("%lf", &time);
    printf("Enter the rate (%%): ");
    scanf("%lf", &rate);

    si = (principal * time * rate) / 100;
    printf("Simple interest = %.2f\n", si);
}

/* ===== Menu: choose which program to run ===== */
int main(void)
{
    int choice;

    printf("Week 2: Formulas and Conditions\n");
    printf("1. bank_loan\n");
    printf("2. compound_interest\n");
    printf("3. cylinder\n");
    printf("4. simple_interest\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;   /* clear the leftover newline */
    printf("\n");

    switch (choice) {
        case 1: task_bank_loan(); break;
        case 2: task_compound_interest(); break;
        case 3: task_cylinder(); break;
        case 4: task_simple_interest(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
