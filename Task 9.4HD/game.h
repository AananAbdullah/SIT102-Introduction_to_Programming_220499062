#ifndef GAME
#define GAME

#include "splashkit.h"
#include "cars.h"
#include "obstacles.h"
#include<vector>

using std::vector;
using namespace std;

#define LOCATION 1000
#define SPOT 800


/**
 * The game data keeps track of all of the information related to the car and obstacles.
 * 
 * @field   car_data                    All the car information which is in turn stored in the car_data struct
 * @field   vector<obstacle_data>       All the obstacle information stored in a dynamic array
 * @field   counter                     The integer value used to create a timer
 */
struct game_data
{
    car_data   car;
    vector<obstacle_data>obstacles;
    int          counter;
};

/**
 * Function to convert the string input line from the terminal to an integer and return the converted 
 * integer
 * @param prompt       The message displayed to the terminal
 * @returns            The converted integer value
 */
int read_integer(string prompt);

/**
 * Procedure to display a menu in the terminal where user can choose option for custom message
 * @param game          This contains all the information about both cars and obstacles
 */
void display_character_message(game_data &game);

/**
 * Procedure to customize the icons and measurements in the game's header display
 * @param game          This contains all the information about both cars and obstacles
 */
void display_header(game_data game);

/**
 * Function to create a new game which in turn calls the start_car() function
 * 
 * @returns            The new game data 
 */
game_data new_game();

/**
 * Procedure to add obstacles to the screen
 * @param game       This contains all the information about both cars and obstacles
 */
void add_obstacle(game_data &game);

/**
 * Procedure to adjust points,fuel energy,stars,and other game variables when an obstacle
 * is accessed by car
 * @param game       This contains all the information about both cars and obstacles
 */
void apply_obstacle(game_data &game);

/**
 * Procedure to remove obstacle once car hits it
 * @param game       This contains all the information about both cars and obstacles
 * @param index      This is the index number of a specific obstacle from the whole array
 */
void remove_obstacle(game_data &game,int index);

/**
 * Procedure to check collisions between car and obstacle to then change the game 
 * variables and remove the obstacle
 * @param game       This contains all the information about both cars and obstacles
 */
void check_collisions(game_data &game);

/**
 * Procedure to update the entire game including car and obstacles
 * @param game       This contains all the information about both cars and obstacles
 */
void update_game(game_data &game);

#endif