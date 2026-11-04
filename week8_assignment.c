/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 8: Structures
 */
#include <stdio.h>
#include <string.h>

/* ===== patient.c ===== */
/* patient.c - Patient admission report using a structure */

struct Patient {
    char id[15];
    char name[50];
    int age;
    char gender[10];
    char diagnosis[50];
    int daysAdmitted;
};

void task_patient(void)
{
    struct Patient p;

    printf("Enter Patient ID: ");
    scanf("%14s", p.id);
    getchar();
    printf("Enter Patient Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0';
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf("%9s", p.gender);
    getchar();
    printf("Enter Diagnosis: ");
    fgets(p.diagnosis, sizeof(p.diagnosis), stdin);
    p.diagnosis[strcspn(p.diagnosis, "\n")] = '\0';
    printf("Enter Number of Days Admitted: ");
    scanf("%d", &p.daysAdmitted);

    printf("\n---------------------------------------\n");
    printf(" PATIENT ADMISSION REPORT\n");
    printf("---------------------------------------\n");
    printf("Patient ID    : %s\n", p.id);
    printf("Patient Name  : %s\n", p.name);
    printf("Age           : %d\n", p.age);
    printf("Gender        : %s\n", p.gender);
    printf("Diagnosis     : %s\n", p.diagnosis);
    printf("Days Admitted : %d\n", p.daysAdmitted);
}

/* ===== payroll.c ===== */
/* payroll.c - Employee payroll using an array of structures */

#define SIZE 3

/* (i) Employee structure */
struct Employee {
    char id[10];
    char name[40];
    char department[20];
    double basicSalary;
    double allowance;
};

/* (ii) Gross Salary = Basic Salary + Allowance */
double calculateGrossSalary(struct Employee e)
{
    return e.basicSalary + e.allowance;
}

/* Formats a number with thousands separators and 2 decimals, e.g. 58000 -> 58,000.00 */
void formatMoney(double value, char *out)
{
    char tmp[40];
    int len, i, j = 0;
    char *dot;

    sprintf(tmp, "%.2f", value);
    dot = strchr(tmp, '.');
    len = (int) (dot - tmp);
    for (i = 0; i < len; i++) {
        if (i > 0 && (len - i) % 3 == 0)
            out[j++] = ',';
        out[j++] = tmp[i];
    }
    strcpy(out + j, dot);
}

void task_payroll(void)
{
    struct Employee emp[SIZE];              /* (iii) array of three employees */
    char gross[40];
    int i;

    /* (iv) read details with a loop */
    for (i = 0; i < SIZE; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Enter Employee ID: ");
        scanf("%9s", emp[i].id);
        getchar();
        printf("Enter Employee Name: ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        emp[i].name[strcspn(emp[i].name, "\n")] = '\0';
        printf("Enter Department: ");
        scanf("%19s", emp[i].department);
        printf("Enter Basic Salary: ");
        scanf("%lf", &emp[i].basicSalary);
        printf("Enter Allowance: ");
        scanf("%lf", &emp[i].allowance);
    }

    /* (v) display the report with another loop */
    printf("\n---------------------------------------------------------------\n");
    printf(" EMPLOYEE PAYROLL REPORT\n");
    printf("---------------------------------------------------------------\n");
    printf("%-8s%-22s%-14s%s\n", "ID", "Name", "Department", "Gross Salary (Ksh)");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < SIZE; i++) {
        formatMoney(calculateGrossSalary(emp[i]), gross);
        printf("%-8s%-22s%-14s%s\n", emp[i].id, emp[i].name, emp[i].department, gross);
    }
    printf("---------------------------------------------------------------\n");
}

/* ===== vehicle.c ===== */
/* vehicle.c - Vehicle registration report using a structure */

/* (a) structure definition */
struct Vehicle {
    char regNo[15];
    char model[30];
    char manufacturer[30];
    int year;
    double dailyCharge;
};

/* Formats a whole number with thousands separators, e.g. 4500 -> 4,500 */
void formatMoneyLong(long value, char *out)
{
    char tmp[32];
    int len, i, j = 0;

    sprintf(tmp, "%ld", value);
    len = (int) strlen(tmp);
    for (i = 0; i < len; i++) {
        if (i > 0 && (len - i) % 3 == 0)
            out[j++] = ',';
        out[j++] = tmp[i];
    }
    out[j] = '\0';
}

void task_vehicle(void)
{
    struct Vehicle v;                       /* (b) declare a Vehicle variable */
    char fee[32];

    /* (c) read the details */
    printf("Enter Registration Number: ");
    fgets(v.regNo, sizeof(v.regNo), stdin);
    v.regNo[strcspn(v.regNo, "\n")] = '\0';
    printf("Enter Vehicle Model: ");
    fgets(v.model, sizeof(v.model), stdin);
    v.model[strcspn(v.model, "\n")] = '\0';
    printf("Enter Manufacturer: ");
    fgets(v.manufacturer, sizeof(v.manufacturer), stdin);
    v.manufacturer[strcspn(v.manufacturer, "\n")] = '\0';
    printf("Enter Year of Manufacture: ");
    scanf("%d", &v.year);
    printf("Enter Daily Rental Charge (Ksh): ");
    scanf("%lf", &v.dailyCharge);

    formatMoneyLong((long) v.dailyCharge, fee);

    /* (d) display the report */
    printf("\n---------------------------------------------\n");
    printf(" VEHICLE REGISTRATION REPORT\n");
    printf("---------------------------------------------\n");
    printf("Registration No.  : %s\n", v.regNo);
    printf("Vehicle Model     : %s\n", v.model);
    printf("Manufacturer      : %s\n", v.manufacturer);
    printf("Year Manufactured : %d\n", v.year);
    printf("Daily Rental Fee  : Ksh %s\n", fee);
    printf("---------------------------------------------\n");
}

/* ===== Menu: choose which program to run ===== */
int main(void)
{
    int choice;

    printf("Week 8: Structures\n");
    printf("1. patient\n");
    printf("2. payroll\n");
    printf("3. vehicle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;   /* clear the leftover newline */
    printf("\n");

    switch (choice) {
        case 1: task_patient(); break;
        case 2: task_payroll(); break;
        case 3: task_vehicle(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
