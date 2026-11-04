/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 3: If-else and Switch
 */
#include <stdio.h>

/* ===== data_bundle.c ===== */
/* data_bundle.c - Data bundle menu using switch */

void task_data_bundle(void)
{
    int choice;

    printf("Select data bundle:\n");
    printf("1. 100MB @ 50 KES\n");
    printf("2. 500MB @ 200 KES\n");
    printf("3. 1GB @ 350 KES\n");
    printf("4. 2GB @ 600 KES\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("You selected 100MB. Cost = 50 KES\n");  break;
        case 2: printf("You selected 500MB. Cost = 200 KES\n"); break;
        case 3: printf("You selected 1GB. Cost = 350 KES\n");   break;
        case 4: printf("You selected 2GB. Cost = 600 KES\n");   break;
        default: printf("Invalid choice\n");
    }
}

/* ===== exam_eligibility.c ===== */
/* exam_eligibility.c - Eligible if attendance >= 75 AND average marks >= 40 */

void task_exam_eligibility(void)
{
    float attendance, average;

    printf("Enter attendance (%%): ");
    scanf("%f", &attendance);
    printf("Enter average marks: ");
    scanf("%f", &average);

    if (attendance >= 75 && average >= 40)
        printf("Eligible\n");
    else
        printf("Not eligible\n");
}

/* ===== water_bill.c ===== */
/* water_bill.c - Tiered water bill:
   first 30 units @ 20, next 30 units (31-60) @ 25, above 60 @ 30 */

void task_water_bill(void)
{
    int units;
    double bill;

    printf("Enter water units consumed: ");
    scanf("%d", &units);

    if (units <= 30)
        bill = units * 20.0;
    else if (units <= 60)
        bill = 30 * 20.0 + (units - 30) * 25.0;
    else
        bill = 30 * 20.0 + 30 * 25.0 + (units - 60) * 30.0;

    printf("Total water bill: %.2f KES\n", bill);
}

/* ===== Menu: choose which program to run ===== */
int main(void)
{
    int choice;

    printf("Week 3: If-else and Switch\n");
    printf("1. data_bundle\n");
    printf("2. exam_eligibility\n");
    printf("3. water_bill\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;   /* clear the leftover newline */
    printf("\n");

    switch (choice) {
        case 1: task_data_bundle(); break;
        case 2: task_exam_eligibility(); break;
        case 3: task_water_bill(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
