/*
 * Name       : KURIA ERNEST MWANGI
 * Reg Number : CT100/G/30614/26
 * Week 6: Arrays
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===== hotel_arrays.c ===== */
/* hotel_arrays.c - Hotel management using 1D, 2D and 3D arrays */

#define DAYS 7
#define BRANCHES 3
#define FLOORS 5
#define ROOMS 10

int main(void)
{
    double revenue[DAYS], total = 0;
    int occupancy[FLOORS][ROOMS];
    int chain[BRANCHES][FLOORS][ROOMS];
    int b, f, r, d, occupied, chainOccupied = 0;

    srand((unsigned) time(NULL));

    /* ---- 1D array: weekly revenue ---- */
    printf("=== Weekly Revenue ===\n");
    for (d = 0; d < DAYS; d++) {
        printf("Enter revenue for day %d: ", d + 1);
        scanf("%lf", &revenue[d]);
        total += revenue[d];
    }
    printf("Total weekly revenue   : %.2f\n", total);
    printf("Average daily revenue  : %.2f\n", total / DAYS);

    /* ---- 2D array: one branch occupancy (simulated) ---- */
    printf("\n=== Room Occupancy (One Branch) ===\n");
    for (f = 0; f < FLOORS; f++)
        for (r = 0; r < ROOMS; r++)
            occupancy[f][r] = rand() % 2;      /* 1 = occupied, 0 = vacant */

    for (f = 0; f < FLOORS; f++) {
        occupied = 0;
        for (r = 0; r < ROOMS; r++)
            occupied += occupancy[f][r];
        printf("Floor %d: Occupied = %d, Vacant = %d\n", f + 1, occupied, ROOMS - occupied);
    }

    /* ---- 3D array: whole chain ---- */
    printf("\n=== Hotel Chain ===\n");
    for (b = 0; b < BRANCHES; b++)
        for (f = 0; f < FLOORS; f++)
            for (r = 0; r < ROOMS; r++) {
                chain[b][f][r] = rand() % 2;
                chainOccupied += chain[b][f][r];
            }
    printf("Total occupied rooms across all branches: %d out of %d\n",
           chainOccupied, BRANCHES * FLOORS * ROOMS);
    return 0;
}
