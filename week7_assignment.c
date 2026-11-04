/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 7: C Files
 */
#include <stdio.h>
#include <string.h>

/* ===== borrowed_books.c ===== */
/* borrowed_books.c - Append book titles to borrowed_books.txt without deleting old records */

void task_borrowed_books(void)
{
    FILE *fp;
    char title[100];

    fp = fopen("borrowed_books.txt", "a");   /* "a" = append mode keeps existing records */
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    printf("Enter the book title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';      /* remove the newline */

    fprintf(fp, "%s\n", title);
    fclose(fp);

    printf("Title \"%s\" stored successfully.\n", title);
}

/* ===== read_results.c ===== */
/* read_results.c - Read student records from the binary file results.dat */

struct Student {
    char name[50];
    char regNo[20];
    float totalMarks;
};

void task_read_results(void)
{
    FILE *fp;
    struct Student s;

    fp = fopen("results.dat", "rb");        /* rb = read binary */
    if (fp == NULL) {
        printf("Error: could not open results.dat\n");
        return;
    }

    printf("%-25s %s\n", "Name", "Marks");
    printf("------------------------------------\n");
    while (fread(&s, sizeof(struct Student), 1, fp) == 1)
        printf("%-25s %.1f\n", s.name, s.totalMarks);

    fclose(fp);
}

/* ===== total_sales.c ===== */
/* total_sales.c - Read amounts from sales.txt and display the day's total */

void task_total_sales(void)
{
    FILE *fp;
    double amount, total = 0;

    fp = fopen("sales.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open sales.txt\n");
        return;
    }

    while (fscanf(fp, "%lf", &amount) == 1)
        total += amount;

    fclose(fp);                              /* always close the file */

    printf("Total sales for the day: %.2f\n", total);
}

/* ===== Menu: choose which program to run ===== */
int main(void)
{
    int choice;

    printf("Week 7: C Files\n");
    printf("1. borrowed_books\n");
    printf("2. read_results\n");
    printf("3. total_sales\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;   /* clear the leftover newline */
    printf("\n");

    switch (choice) {
        case 1: task_borrowed_books(); break;
        case 2: task_read_results(); break;
        case 3: task_total_sales(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
