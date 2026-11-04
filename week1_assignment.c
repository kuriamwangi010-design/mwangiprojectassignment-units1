/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 1: Basic Input and Output
 */
#include <stdio.h>

/* ===== units.c ===== */
/* units.c - Displays the academic units offered this semester */

void task_units(void)
{
    printf("Units Offered This Semester:\n");
    printf("1. Introduction to Programming\n");
    printf("2. Data Structures\n");
    printf("3. Computer Networks\n");
    printf("4. Database Systems\n");
    printf("5. Software Engineering\n");
}

/* ===== user_input.c ===== */
/* user_input.c - Reads height, bank balance and phone number, then displays them */

void task_user_input(void)
{
    float height;          /* height in meters */
    double balance;        /* bank balance in KES */
    char phone[20];        /* phone number kept as a string so the leading 0 is not lost */

    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("Enter your bank balance (KES): ");
    scanf("%lf", &balance);

    printf("Enter your phone number: ");
    scanf("%19s", phone);

    printf("\n----- Your Details -----\n");
    printf("Height       : %.2f m\n", height);
    printf("Bank balance : KES %.2f\n", balance);
    printf("Phone number : %s\n", phone);
}

/* ===== Menu: choose which program to run ===== */
int main(void)
{
    int choice;

    printf("Week 1: Basic Input and Output\n");
    printf("1. units\n");
    printf("2. user_input\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;   /* clear the leftover newline */
    printf("\n");

    switch (choice) {
        case 1: task_units(); break;
        case 2: task_user_input(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
