// hackathon.c (cleaned)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "hackathon.h"

#define SIZE 8

void initialize_Map(char map[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            map[r][c] = '*';
        }
    }
}

void print_map(char map[SIZE][SIZE]) {
    // Print column headers
    printf("  A B C D E F G H");
    printf("\n");

    for (int row = 0; row < SIZE; row++) {
        printf("%d ", row + 1); // row header
        for (int col = 0; col < SIZE; col++) {
            char val = map[row][col];
            if (val == 'S') {
                printf("\033[0;35m%c \033[0m", val);
            } else if (val == 'X') {
                printf("\033[0;31m%c \033[0m", val);
            } else if (val == 'O') {
                printf("\033[0;37m%c \033[0m", val);
            } else if (val == '*') {
                printf("\033[0;33m%c \033[0m", val);
            } else {
                printf("%c ", val);
            }
        }
        printf("\n");
    }
}


int can_place_ship(char *base, char *ptr, int length, int direction) {
    /* base and ptr must point into the same map (base = &map[0][0]) */
    int index = (int)(ptr - base);
    int row = index / SIZE;
    int col = index % SIZE;

    /* Check bounds first */
    switch (direction) {
        case 0: 
            if (col + length > SIZE) 
            return 0; 
        break; // right
        case 1: 
            if (col - (length - 1) < 0) 
            return 0; 
        break; // left
        case 2: 
            if (row - (length - 1) < 0) 
            return 0; 
        break; // up
        case 3: 
            if (row + length > SIZE) 
            return 0; 
        break; // down
    }

    /* Check if all spots are open */
    for (int i = 0; i < length; i++) {
        char *current;
        switch (direction) {
            case 0: 
                current = ptr + i; 
                break;           // right
            case 1: 
                current = ptr - i; 
                break;           // left
            case 2: 
                current = ptr - i*SIZE; 
                break;      // up
            case 3: 
                current = ptr + i*SIZE; 
                break;      // down
            default: 
                current = ptr; 
                break;
        }
        if (!check_open(current)) return 0;
    }

    return 1; // valid placement
}

void place_two(char map[SIZE][SIZE]) {
    char *base = &map[0][0];
    int length = 2;
    int placed = 0;
    int attempts = 0;
    const int MAX_ATTEMPTS = 25;

    while (!placed && attempts++ < MAX_ATTEMPTS) {
        int random_index = rand() % (SIZE * SIZE);
        char *ptr = base + random_index;
        int direction = rand() % 4;

        if (can_place_ship(base, ptr, length, direction)) {
            for (int i = 0; i < length; i++) {
                char *current;
                switch (direction) {
                    case 0: 
                        current = ptr + i; 
                        break;
                    case 1: 
                        current = ptr - i; 
                        break;
                    case 2: 
                        current = ptr - i*SIZE; 
                        break;
                    default: 
                        current = ptr + i*SIZE; 
                        break;
                }
                *current = 'S';
            }
            placed = 1;
        }
    }

    if (!placed) fprintf(stderr, "place_two: failed to place ship after %d attempts\n", MAX_ATTEMPTS);
}

void place_three(char map[SIZE][SIZE]) {
    char *base = &map[0][0];
    int length = 3;
    int placed = 0;
    int attempts = 0;
    const int MAX_ATTEMPTS = 10000;

    while (!placed && attempts++ < MAX_ATTEMPTS) {
        int random_index = rand() % (SIZE * SIZE);
        char *ptr = base + random_index;
        int direction = rand() % 4;

        if (can_place_ship(base, ptr, length, direction)) {
            for (int i = 0; i < length; i++) {
                char *current;
                switch (direction) {
                    case 0: 
                        current = ptr + i; 
                        break;
                    case 1: 
                        current = ptr - i; 
                        break;
                    case 2:
                        current = ptr - i*SIZE; 
                        break;
                    default: 
                        current = ptr + i*SIZE; 
                        break;
                }
                *current = 'S';
            }
            placed = 1;
        }
    }

    if (!placed) fprintf(stderr, "place_three: failed to place ship after %d attempts\n", MAX_ATTEMPTS);
}

void place_four(char map[SIZE][SIZE]) {
    char *base = &map[0][0];
    int length = 4;
    int placed = 0;
    int attempts = 0;
    const int MAX_ATTEMPTS = 10000;

    while (!placed && attempts++ < MAX_ATTEMPTS) {
        int random_index = rand() % (SIZE * SIZE);
        char *ptr = base + random_index;
        int direction = rand() % 4;

        if (can_place_ship(base, ptr, length, direction)) {
            for (int i = 0; i < length; i++) {
                char *current;
                switch (direction) {
                    case 0: 
                        current = ptr + i; 
                        break;
                    case 1: 
                        current = ptr - i; 
                        break;
                    case 2: 
                        current = ptr - i*SIZE; 
                        break;
                    default: 
                        current = ptr + i*SIZE; 
                        break;
                }
                *current = 'S';
            }
            placed = 1;
        }
    }

    if (!placed) fprintf(stderr, "place_four: failed to place ship after %d attempts\n", MAX_ATTEMPTS);
}

void place_five(char map[SIZE][SIZE]) {
    char *base = &map[0][0];
    int length = 5;
    int placed = 0;
    int attempts = 0;
    const int MAX_ATTEMPTS = 10000;

    while (!placed && attempts++ < MAX_ATTEMPTS) {
        int random_index = rand() % (SIZE * SIZE);
        char *ptr = base + random_index;
        int direction = rand() % 4;

        if (can_place_ship(base, ptr, length, direction)) {
            for (int i = 0; i < length; i++) {
                char *current;
                switch (direction) {
                    case 0: current = ptr + i; break;
                    case 1: current = ptr - i; break;
                    case 2: current = ptr - i*SIZE; break;
                    default: current = ptr + i*SIZE; break;
                }
                *current = 'S';
            }
            placed = 1;
        }
    }

    if (!placed) fprintf(stderr, "place_five: failed to place ship after %d attempts\n", MAX_ATTEMPTS);
}

void place_ships(char map[SIZE][SIZE]) {
    place_two(map);
    place_three(map);
    place_four(map);
    place_five(map);
}



int check_open(char *ptr) {
    return (*ptr == '*') ? 1 : 0;
}

/* keep static counters inside these functions (as you had them) */
int user_ships_subtract(void) {
    static int userShips = 14;
    userShips--;
    return userShips;
}

int alien_ships_subtract(void) {
    static int alienShips = 14;
    alienShips--;
    return alienShips;
}


void update_grid_hit_user(char *basePtr, int row, int col) {
    char *p = basePtr + (row * SIZE + col);
    *p = 'X';
    user_ships_subtract();
}

void update_grid_miss_user(char *basePtr, int row, int col) {
    char *p = basePtr + (row * SIZE + col);
    *p = 'O';
}

void update_grid_hit_alien(char *basePtr, int row, int col) {
    char *p = basePtr + (row * SIZE + col);
    *p = 'X';
    alien_ships_subtract();
}

void update_grid_miss_alien(char *basePtr, int row, int col) {
    char *p = basePtr + (row * SIZE + col);
    *p = 'O';
}

void update_shot_map_hit(char *basePtr, int row, int col) {
    char *p = basePtr + (row * SIZE + col);
    *p = 'X';
}

void update_shot_map_miss(char *basePtr, int row, int col) {
    char *p = basePtr + (row * SIZE + col);
    *p = 'O';
}


/* user shoots at alien's base (base pointer to alien map), row/col are 0-based */
int user_shot_function(char *alienBase, int userRow, int userCol) {
    char *target = alienBase + (userRow * SIZE + userCol);

    if (check_open(target)) {
        printf("You Missed!\n");
        update_grid_miss_alien(alienBase, userRow, userCol);
        return 0;
    } else if (*target == 'S') {
        printf("You got a hit!\n");
        update_grid_hit_alien(alienBase, userRow, userCol);
        return 1;
    } else if (*target == 'O' || *target == 'X') {
        printf("You already shot there, try again\n");
        return -1;
    } else {
        printf("Please try again, Invalid index\n");
        return -2;
    }
}



int alien_shot_function(char *userBase) {
    static int targetMode = 0; 
    static int lastHitRow = -1;
    static int lastHitCol = -1;
    static int tried[SIZE][SIZE] = {0};

    int row = -1, col = -1;

    if (targetMode) {
        int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int found = 0;
        for (int i = 0; i < 4; ++i) {
            int nr = lastHitRow + directions[i][0];
            int nc = lastHitCol + directions[i][1];
            if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && !tried[nr][nc]) {
                row = nr;
                col = nc;
                found = 1;
                break;
            }
        }
        if (!found) {
            targetMode = 0;
        }
    }

    if (!targetMode) {
        do {
            row = rand() % SIZE;
            col = rand() % SIZE;
        } while (tried[row][col]);
    }

    // Mark tried now (exactly once per shot)
    tried[row][col] = 1;

    char *target = userBase + (row * SIZE + col);

    if (*target == 'S') {
        printf("Alien hits"); 
        update_grid_hit_user(userBase, row, col);
        targetMode = 1;
        lastHitRow = row;
        lastHitCol = col;
        return 1;
    } else if (*target == '*') {
        printf("Alien misses");
        update_grid_miss_user(userBase, row, col);
        return 0;
    } else {
        // If we somehow picked a previously non-* non-S cell, treat as miss
        printf("Alien shot at a previously targeted cell (%d,%d).\n", row + 1, col + 1);
        return -1;
    }
}

int check_open_repeat(char map[SIZE][SIZE], int userRow, int userCol){
    if(map[userRow][userCol] == 'S'){
        return 1;
    } else if(map[userRow][userCol] == '*'){
        return 0;
    } else if(map[userRow][userCol] == 'X'){
        return -1;
    } else {
        return -2;
    }
}

