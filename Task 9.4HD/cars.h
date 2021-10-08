#ifndef CARS
#define CARS

#include "splashkit.h"

using namespace std;

#define BORDER 20
#define MAX 2000
#define MIN 2000
#define CAR_SPEED 1.0
#define CAR_ROTATE_SPEED 2.5

/**
 * Enumeration listing the character names
 */
enum character_type
{
    POISON,
    COURAGE,
    JOKER,
    FAIRIE,
    DRAGON

};
/**
 * Enumeration for the different car colors
 */
enum car_type
{
    BLUE,
    RED,
    YELLOW
};

/**Struct containing all the data about the cars
 * @field   car_sprite      The car's sprite - used to track position and movement
 * @field   cars            Current car color
 * @field   fuel            Measurement of the car's fuel
 * @field   star            Another reward method
 * @field   points          The current points for the car
 * @field   name            The user's chosen character name
 */
struct car_data
{
    sprite       car_sprite;
    car_type     cars;
    double       fuel;
    int          star;
    int          points;
    string       name;
};

/**
 * Function that has switch-case statements that outline which scenario would return which car bitmap
 * @param car       The values from the car_type enumeration that determine each case
 * @returns         The bitmap of the chosen car
 */  
bitmap car_choice(car_type car);

/**
 * Function to create a new car and initialize all the other values in the car_data struct such as
 * fuel,star,points,etc.
 */
car_data start_car();

/**
 * Procedure to display the most updated version of a car
 * @param car     The car that will be displayed on the screen
 */ 
void draw_car(const car_data &car_to_draw);

/**
 * Procedure to update the details and position of the car
 * @param car_to_update   The car that will be updated to be later displayed to the screen
 */
void update_car(car_data &car_to_update);

/**
 * Procedure that determines how a car will be changed based on user input
 * @param car      The chosen car
 * @param choice   Indicates which numbered car was chosen
 */
void choose_car(car_data &car, car_type choice);

/**
 * Procedure that lists a bunch of keyboard keys that the user can press to change the car color
 * @param car      The car that will be chosen and displayed to the screen
 */
void input_choices(car_data &car);

#endif