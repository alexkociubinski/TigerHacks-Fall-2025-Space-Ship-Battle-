#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

//COMPLETE FUNCTIONS
int check_open(char *ptr);
void initialize_Map(char map[SIZE][SIZE]); // function complete
void print_map(char map[SIZE][SIZE]); // function complete
void place_two(char map[SIZE][SIZE]); // function complete
void place_three(char map[SIZE][SIZE]); // function complete
void place_four(char map[SIZE][SIZE]); // function complete
void place_five(char map[SIZE][SIZE]); // function complete
void place_ships(char map[SIZE][SIZE]); // function complete
int can_place_ship(char *base, char *ptr, int length, int direction); // function complete
int user_ships_subtract(void); // check how many ships are left 
int alien_ships_subtract(void); //check how many ships are left 
int user_shot_function(char *ptr, int userRow, int userCol); //returns 0 if miss , 1 if hit, function complete
int alien_shot_function(char *userMap);//function complete
void update_grid_hit_user(char *ptr, int userRow, int userCol);
void update_grid_miss_user(char *ptr, int userRow, int userCol);
void update_grid_hit_alien(char *ptr, int userRow, int userCol);
void update_grid_hit_alien(char *ptr, int userRow, int userCol);
void update_shot_map_miss(char *ptr, int row, int col);
void update_shot_map_hit(char *ptr, int row, int col);
int check_open_repeat(char map[SIZE][SIZE], int userRow, int userCol); //function complete
//COMPLETE FUNCTIONS



