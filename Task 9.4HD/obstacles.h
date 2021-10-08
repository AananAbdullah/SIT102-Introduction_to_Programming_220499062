#ifndef OBSTACLES
#define OBSTACLES

#include "splashkit.h"


using namespace std;

/**
 * Enumeration listing the obstacle names
 */
enum obstacle_type
{
    DANGER,
    HELMET,
    TREASURE,
    BALLOON
};

/**
 * Struct containing all the data about obstacles
 * @field     obstacle_sprite      The obstacle's sprite-used to track position and movement
 * @field     obstacle             Current obstacle type
 */
struct obstacle_data
{
    sprite          obstacle_sprite;
    obstacle_type   obstacle;
};

/**
 * Function that has switch-case statements that outline which scenario would return which obstacle bitmap
 * @param kind       The values from the obstacle_type enumeration that determine each case
 * @returns          The bitmap of the chosen obstacle
 */  
bitmap obstacle_bitmap(obstacle_type kind);
/**
 * Function that creates an obstacle at the location coordinates passed in the input parameters
 * 
 * @param x    The x-coordinate of the obstacle's location
 * @param y    The y-coordinate of the obstacle's location
 * @returns    The new obstacle's data
 */
obstacle_data new_obstacle(double x,double y);
/**
 * Procedure to draw the obstacle to the screen
 * 
 * @param obstacle_to_draw  The obstacle to draw to the screen
 */
void draw_obstacle(const obstacle_data &obstacle_to_draw);
/**
 * Procedure with actions to update the obstacle's position
 * 
 * @param obstacle_to_update  The obstacle being updated
 */
void update_obstacle(obstacle_data &obstacle_to_update);

#endif