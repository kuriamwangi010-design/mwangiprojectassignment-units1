/*
NAME: ERNEST MWANGI
REG NO: CT100/G/30614/26
DESCRIPTION: VARIABLES AND DATA TYPES DEMONSTRATION
DATE: 25/9/2026
*/

#include <stdio.h>

int main() {
    // Student Information
    printf("Name: Ernest Mwangi\n");
    printf("Reg No: CT100/G/30614/26\n");
    printf("-------------------------------\n\n");

    // Declare and initialize variables 
    char grade = 'A';        // %c
    char name[21] = "James"; // %s
    int age = 21;            // %d
    float marks = 70.0;      // %f
    double pi = 3.142;       // %lf

    printf("Enter your grade:\t");
    scanf(" %c", &grade);

    printf("Enter your name:\t");
    scanf("%20s", name);

    printf("Enter your age:\t");
    scanf("%d", &age);

    printf("Enter your marks:\t");
    scanf("%f", &marks);

    printf("Enter the value of pi:\t");
    scanf("%lf", &pi);

    printf("\n--- Output ---\n");
    printf("The grade is %c \n", grade);
    printf("My name is %s \n", name);
    printf("I am %d years old \n", age);
    printf("I scored %.2f marks in KCSE \n", marks);
    printf("The value of pi is %.3lf \n", pi);

    return 0;
}
