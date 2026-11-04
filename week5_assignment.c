/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 5: Functions
 */
#include <stdio.h>

/* ===== celsius.c ===== */
/* celsius.c - Convert Fahrenheit to Celsius: C = (F - 32) * 5/9 */

double convertToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;   /* 5.0/9.0 avoids integer division */
}

void task_celsius(void)
{
    double f;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &f);
    printf("Temperature in Celsius: %.1f C\n", convertToCelsius(f));
}

/* ===== electric_bill.c ===== */
/* electric_bill.c - First 100 units @10, next 100 @15, above 200 @20 */

double calculateElectricBill(int units)
{
    double bill;

    if (units <= 100)
        bill = units * 10.0;
    else if (units <= 200)
        bill = 100 * 10.0 + (units - 100) * 15.0;
    else
        bill = 100 * 10.0 + 100 * 15.0 + (units - 200) * 20.0;
    return bill;
}

void task_electric_bill(void)
{
    int units;

    printf("Enter units consumed: ");
    scanf("%d", &units);
    printf("Total bill: KSh. %.2f\n", calculateElectricBill(units));
}

/* ===== fare.c ===== */
/* fare.c - Fare at KSh. 50 per kilometre */

double calculateFare(double distance)
{
    return distance * 50.0;
}

void task_fare(void)
{
    double distance;

    printf("Enter distance travelled (km): ");
    scanf("%lf", &distance);
    printf("Total fare: KSh. %.2f\n", calculateFare(distance));
}

/* ===== Menu: choose which program to run ===== */
int main(void)
{
    int choice;

    printf("Week 5: Functions\n");
    printf("1. celsius\n");
    printf("2. electric_bill\n");
    printf("3. fare\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;   /* clear the leftover newline */
    printf("\n");

    switch (choice) {
        case 1: task_celsius(); break;
        case 2: task_electric_bill(); break;
        case 3: task_fare(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
