/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 4: Loops
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===== atm_withdrawal.c ===== */
/* atm_withdrawal.c - Withdraw until the balance is zero or negative */

void task_atm_withdrawal(void)
{
    double balance, amount;

    printf("Enter your starting account balance: ");
    scanf("%lf", &balance);

    while (balance > 0) {
        printf("Enter amount to withdraw: ");
        scanf("%lf", &amount);
        balance = balance - amount;   /* the balance may go to zero or negative */
        printf("Balance after withdrawal: %.2f\n", balance);
    }

    printf("Balance is zero or negative. No more withdrawals allowed.\n");
}

/* ===== for_loop.c ===== */
/* for_loop.c - Prints 100 down to 50, one per line */

void task_for_loop(void)
{
    int i;
    for (i = 100; i >= 50; i--)
        printf("%d\n", i);
}

/* ===== guessing_game.c ===== */
/* guessing_game.c - Guess a random number between 1 and 20 */

void task_guessing_game(void)
{
    int secret, guess, attempts = 0;

    srand((unsigned) time(NULL));      /* seed the random generator */
    secret = rand() % 20 + 1;          /* number from 1 to 20 inclusive */

    printf("I have picked a number between 1 and 20. Try to guess it!\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > secret)
            printf("Too high!\n");
        else if (guess < secret)
            printf("Too low!\n");
        else
            printf("Congratulations!\n");
    } while (guess != secret);

    printf("You guessed it in %d attempt(s).\n", attempts);
}

/* ===== password_login.c ===== */
/* password_login.c - Keep asking until the password 1234 is entered */

void task_password_login(void)
{
    int password;

    do {
        printf("Enter password: ");
        scanf("%d", &password);
    } while (password != 1234);

    printf("Access Granted\n");
}

/* ===== Menu: choose which program to run ===== */
int main(void)
{
    int choice;

    printf("Week 4: Loops\n");
    printf("1. atm_withdrawal\n");
    printf("2. for_loop\n");
    printf("3. guessing_game\n");
    printf("4. password_login\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;   /* clear the leftover newline */
    printf("\n");

    switch (choice) {
        case 1: task_atm_withdrawal(); break;
        case 2: task_for_loop(); break;
        case 3: task_guessing_game(); break;
        case 4: task_password_login(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
