#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hackathon.h"

#define SIZE 8

// forward declarations
void initialize_Map(char map[SIZE][SIZE]);
void print_map(char map[SIZE][SIZE]);
void place_ships(char map[SIZE][SIZE]);
int user_shot_function(char *ptr, int userRow, int userCol);
void update_grid_hit_user(char *ptr, int userRow, int userCol);
void update_grid_miss_user(char *ptr, int userRow, int userCol);
void update_grid_hit_alien(char *ptr, int randRow, int randCol);
void update_grid_miss_alien(char *ptr, int randRow, int randCol);
int alien_shot_function(char *userMap);
int check_open_repeat(char map[SIZE][SIZE], int userRow, int userCol);




int main(void) {
    int startInt = 0;
    
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
      printf("║              SPACE DEFENSE: OPERATION XYLON                ║\n");
      printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    printf("The year is 4025, humanity has colonized the outer rim of the Milky Way Galaxy.\n");
    printf("Planet Xylon, known for their rare minerals, has become the target of an Alien Attack.\n\n");
    printf("  YOUR MISSION:\n");
    printf("   1. Defend the population living on Planet Xylon.\n");
    printf("   2. Destroy the Alien Ships before they destroy your fleet and invade Planet Xylon.\n\n");
    printf("Enter '1' to accept the mission: ");
    scanf("%d", &startInt);

    if (startInt == 1) {
        startInt = 0;
        printf("\n\n╔════════════════════════════════════════════════════════════╗\n");
            printf("║                         BRIEFING                           ║\n");
            printf("╚════════════════════════════════════════════════════════════╝\n");
        printf("RULES OF ENGAGEMENT:\n");
        printf("  • Take turns firing at enemy coordinates\n");
        printf("  • Direct hits grant another shot immediately\n");
        printf("  • Ships marked as 'S', hits as 'X', misses as 'O'\n");
        printf("  • Destroy all enemy vessels to complete the mission\n\n");

        printf("If you are ready for battle, enter '1' to deploy: ");
        scanf("%d", &startInt);

        if (startInt == 1) {
            printf("\n");

            srand(time(NULL));
            
            char userMap[SIZE][SIZE];
            char alienMap[SIZE][SIZE];
            char shotMap[SIZE][SIZE];
            
            initialize_Map(userMap);
            initialize_Map(alienMap);
            initialize_Map(shotMap);
            
            printf("Deploying your defensive fleet...\n");
            place_ships(userMap);
            printf("Enemy forces detected and locked...\n");
            place_ships(alienMap);
            
            
            printf("═══════════════════════════════════════════════════════════\n");
            printf("               YOUR TARGETING GRID \n");
            printf("═══════════════════════════════════════════════════════════\n");
            print_map(shotMap);
            
            printf("\n═══════════════════════════════════════════════════════════\n");
            printf("               YOUR DEFENSIVE GRID \n");
            printf("═══════════════════════════════════════════════════════════\n");
            print_map(userMap);
            
            printf("\n\nTHE BATTLE BEGINS!\n\n");
            
            char *userBase = &userMap[0][0];
            char *alienBase = &alienMap[0][0];
            char *shotBase = &shotMap[0][0];
            
            int userShips = 14;
            int alienShips = 14;
            int goAgain = 0;
            int totalShots = 0;
            int totalHits = 0;
            int turnNumber = 1;
            
            while (userShips > 0 && alienShips > 0) {
                int userRow, userCol;
                char userCharCol;
                
                // User's turn
                do {
                    printf("\n Your turn! Enter target coordinates (Column A-H, Row 1-8): ");
                    scanf(" %c%d", &userCharCol, &userRow);
                    
                    totalShots++;
                    
                    // Convert column letter to index (0-based)
                    switch (userCharCol) {
                        case 'a':
                        case 'A':
                            userCol = 0;
                            break;
                        case 'b':
                        case 'B':
                            userCol = 1;
                            break;
                        case 'c':
                        case 'C':
                            userCol = 2;
                            break;
                        case 'd':
                        case 'D':
                            userCol = 3;
                            break;
                        case 'e':
                        case 'E':
                            userCol = 4;
                            break;
                        case 'f':
                        case 'F':
                            userCol = 5;
                            break;
                        case 'g':
                        case 'G':
                            userCol = 6;
                            break;
                        case 'h':
                        case 'H':
                            userCol = 7;
                            break;
                        default:
                            printf("Invalid column input\n");
                            userCol = -1;
                            totalShots--; // Don't count invalid shots
                            continue;
                    }
                    
                    userRow -= 1;
                    
                    if (userRow < 0 || userRow >= SIZE || userCol < 0 || userCol >= SIZE) {
                        printf("Coordinates out of range. Try again.\n");
                        totalShots--; // Don't count invalid shots
                        continue;
                    }
                    
                    int result = check_open_repeat(alienMap, userRow, userCol);
                    if (result == 1) {
                        printf("DIRECT HIT at %c%d! Enemy vessel damaged!\n", 
                               (char)(userCol + 'A'), userRow + 1);
                        update_grid_hit_alien(shotBase, userRow, userCol);
                        alienShips--;
                        totalHits++;
                        goAgain = 1;
                    } else if (result == 0) {
                        printf("MISS at %c%d. Shot passed through empty space.\n", 
                               (char)(userCol + 'A'), userRow + 1);
                        update_grid_miss_alien(shotBase, userRow, userCol);
                        goAgain = 0;
                    } else if (result == -1) {
                        printf("Already fired at %c%d. Choose new coordinates.\n", 
                               (char)(userCol + 'A'), userRow + 1);
                        totalShots--; // Don't count repeat shots
                        continue;
                    } else {
                        printf("Invalid shot. Try again.\n");
                        totalShots--; // Don't count invalid shots
                        continue;
                    }
                    
                    printf("\n═══════════════════════════════════════════════════════════\n");
                    printf("                     YOUR TARGETING GRID \n");
                    printf("═══════════════════════════════════════════════════════════\n");
                    print_map(shotMap);
                    printf("Enemy vessels remaining: %d/14\n", alienShips);
                    
                    
                    printf("\n═══════════════════════════════════════════════════════════\n");
                    printf("                     YOUR DEFENSIVE GRID \n");
                    printf("═══════════════════════════════════════════════════════════\n");
                    print_map(userMap);
                    printf("Your vessels remaining: %d/14\n", userShips);
                    
                    
                    if (alienShips <= 0) {
                        printf("\n\n");
                        printf("╔════════════════════════════════════════════════════════════╗\n");
                        printf("║                    MISSION COMPLETE!                       ║\n");
                        printf("╚════════════════════════════════════════════════════════════╝\n\n");
                        printf("All enemy forces have been neutralized!\n");
                        printf("Planet Xylon is safe. The citizens celebrate your victory!\n\n");
                        
                        printf("MISSION STATISTICS:\n");
                        printf("   Turns Completed: %d\n", turnNumber);
                        printf("   Total Shots Fired: %d\n", totalShots);
                        printf("   Successful Hits: %d\n", totalHits);
                        printf("   Accuracy: %.1f%%\n", (totalHits * 100.0) / totalShots);
                        printf("   Mission Rating: ");
                        
                        double accuracy = (totalHits * 100.0) / totalShots;
                        if (accuracy >= 70) {
                            printf("⭐⭐⭐ EXCEPTIONAL MARKSMAN\n");
                        } else if (accuracy >= 50) {
                            printf("⭐⭐ COMPETENT COMMANDER\n");
                        } else {
                            printf("⭐ MISSION ACCOMPLISHED\n");
                        }
                        
                        return 0;
                    }
                } while (goAgain > 0);
                
                goAgain = 0;
                printf("\n--- Turn %d Complete ---\n", turnNumber);
                turnNumber++;
                
                // Alien's turn
                do {
                    printf("\n Enemy targeting systems activated...\n");
                    int alienResult = alien_shot_function(&userMap[0][0]);
                    
                    if (alienResult == 1) {
                        goAgain = 1;
                        userShips--;
                    } else if (alienResult == 0) {
                        goAgain = 0;
                    } else if (alienResult == -1) {
                        continue;
                    }
                    
                    
                    printf("\n═══════════════════════════════════════════════════════════\n");
                    printf("                 YOUR TARGETING GRID \n");
                    printf("═══════════════════════════════════════════════════════════\n");
                    print_map(shotMap);
                    printf("Enemy vessels remaining: %d/14\n", alienShips);
                        
                    printf("\n═══════════════════════════════════════════════════════════\n");
                    printf("                   YOUR DEFENSIVE GRID  \n");
                    printf("═══════════════════════════════════════════════════════════\n");
                    print_map(userMap);
                    printf("Your vessels remaining: %d/14\n", userShips);                        
                    
                    
                    if (userShips <= 0) {
                        printf("\n\n");
                        printf("╔════════════════════════════════════════════════════════════╗\n");
                        printf("║                   MISSION FAILED                           ║\n");
                        printf("╚════════════════════════════════════════════════════════════╝\n\n");
                        printf("All defensive vessels destroyed...\n");
                        printf("The alien forces have invaded Planet Xylon.\n");
                        printf("Humanity's foothold in this sector has been lost.\n\n");
                        
                        printf("FINAL STATISTICS:\n");
                        printf("- Turns Survived: %d\n", turnNumber);
                        printf("- Total Shots Fired: %d\n", totalShots);
                        printf("- Successful Hits: %d\n", totalHits);
                        if (totalShots > 0) {
                            printf("- Accuracy: %.1f%%\n", (totalHits * 100.0) / totalShots);
                        }
                        
                        return 0;
                    }
                } while (goAgain > 0);
                
                goAgain = 0;
            }
        }
    }
    
    printf("\n\nThank you for defending humanity, Commander!\n");
    printf(" SPACE DEFENSE: OPERATION XYLON \n");
    return 0;
}