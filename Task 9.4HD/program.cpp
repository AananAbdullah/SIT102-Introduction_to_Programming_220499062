#include "splashkit.h"
#include "cars.h"
#include "obstacles.h"
#include"game.h"
//cars.h
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

//cars.cpp
#include "cars.h"
#include "splashkit.h"

bitmap car_choice(car_type car)
{
    switch(car)
    {
        case BLUE:
            return bitmap_named("blue");
        case RED:
            return bitmap_named("red");
        default:
            return bitmap_named("yellow");
    }
}

car_data start_car()
{
    car_data new_car;
    bitmap current=car_choice(BLUE);
    new_car.fuel=0.2;
    new_car.star=0;
    new_car.points=0;
    new_car.name="";

    new_car.car_sprite=create_sprite(current);

    sprite_add_layer(new_car.car_sprite, car_choice(RED), "RED");
    sprite_add_layer(new_car.car_sprite, car_choice(YELLOW), "YELLOW");

    sprite_hide_layer(new_car.car_sprite, 1);
    sprite_hide_layer(new_car.car_sprite, 2);

    new_car.cars=BLUE;

    sprite_set_x(new_car.car_sprite,0);
    sprite_set_y(new_car.car_sprite,260);

    return new_car;
}


void draw_car(const car_data &car_to_draw)
{
    draw_sprite(car_to_draw.car_sprite);
}

void update_car(car_data &car_to_update)
{
    // Apply movement based on rotation and velocity in the sprite
    update_sprite(car_to_update.car_sprite);
        
    

    // Test edge of screen boundaries to adjust the camera
    double left_edge = camera_x() + BORDER;
    double right_edge = left_edge + screen_width() - 2 * BORDER;
    double top_edge = camera_y() + BORDER;
    double bottom_edge = top_edge + screen_height() - 2 * BORDER;

    // Get the center of the player
    point_2d sprite_center = center_point(car_to_update.car_sprite);
    
    // Test if the player is outside the area and move the camera
    // the player will appear to stay still and everything else
    // will appear to move :)

    // Test top/bottom of screen
    if (sprite_center.y < top_edge)
    {
        move_camera_by(0, sprite_center.y - top_edge);
    }
    else if (sprite_center.y > bottom_edge)
    {
        move_camera_by(0, sprite_center.y - bottom_edge);
    }

    // Test left/right of screen
    if (sprite_center.x < left_edge)
    {
        move_camera_by(sprite_center.x - left_edge, 0);
    }
    else if (sprite_center.x > right_edge)
    {
        move_camera_by(sprite_center.x - right_edge, 0);
    }
}

void choose_car(car_data &car, car_type choice)
{
    // only do this if there is a change
    if (car.cars != choice)
    {
        // show then hide layers
        sprite_show_layer(car.car_sprite, static_cast<int>(choice));
        sprite_hide_layer(car.car_sprite, static_cast<int>(car.cars));

        // remember what is currently shown
        car.cars = choice;
    }
}

void input_choices(car_data &car)
{
    // Allow the player to switch rollercoaster cars
    if (key_typed(NUM_1_KEY))
        choose_car(car, BLUE);
    else if (key_typed(NUM_2_KEY))
        choose_car(car, RED);
    else if (key_typed(NUM_3_KEY))
        choose_car(car, YELLOW);
    
    float dx = sprite_dx(car.car_sprite);
    float rotation = sprite_rotation(car.car_sprite);

    // Allow rotation with left/right keys
    if (key_down(UP_KEY))
        sprite_set_rotation(car.car_sprite, rotation - CAR_ROTATE_SPEED);
    if (key_down(DOWN_KEY))
        sprite_set_rotation(car.car_sprite, rotation + CAR_ROTATE_SPEED);

    // Increase speed with up/down keys - typed to give step increases
    if (key_typed(LEFT_KEY))
        sprite_set_dx(car.car_sprite, dx - CAR_SPEED);
    if (key_typed(RIGHT_KEY))
        sprite_set_dx(car.car_sprite, dx + CAR_SPEED);
}


//obstacles.h
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

//obstacles.cpp
#include "obstacles.h"
#include "splashkit.h"

bitmap obstacle_bitmap(obstacle_type kind)
{
    switch(kind)
    {
    case DANGER:
        return bitmap_named("danger");
    case HELMET:
        return bitmap_named("helmet");
    case TREASURE:
        return bitmap_named("treasure");
    default:
        return bitmap_named("balloon");
    }
}

obstacle_data new_obstacle(double x,double y)
{
    obstacle_data result;
    
    //Creates a random obstacle from the 4 listed in the enumeration
    result.obstacle_sprite=create_sprite(obstacle_bitmap(static_cast<obstacle_type>(rnd(4))));

    result.obstacle=static_cast<obstacle_type>(rnd(4));

    //Obstacle location
    sprite_set_x(result.obstacle_sprite,x);
    sprite_set_y(result.obstacle_sprite,y);

    //Starting velocity of obstacle
    sprite_set_dx(result.obstacle_sprite,rnd()*3-3);

    return result;
}

void draw_obstacle(const obstacle_data &obstacle_to_draw)
{
    draw_sprite(obstacle_to_draw.obstacle_sprite);
}

void update_obstacle(obstacle_data &obstacle_to_update)
{
    update_sprite(obstacle_to_update.obstacle_sprite);
}

//game.h
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

//game.cpp
#include "splashkit.h"
#include "game.h"
#include"cars.h"
#include "obstacles.h"


int read_integer(string prompt)
{
    string line;
    write(prompt);
    line=read_line();
    return convert_to_integer(line);
}

void display_character_message(game_data &game)
{
    int option;
    
    write_line("Character List");
    write_line("1:Poison");
    write_line("2:Courage");
    write_line("3:Joker");
    write_line("4:Fairie");
    write_line("5:Dragon");
    write_line();
    write_line("*Pick Character Number for a Custom Message*");
    write_line();
    option=read_integer("Character Number: ")-1;
        

        switch(option)
        {
            case POISON:
                write_line("You are a clever soul.");
                game.car.name="Poison";
                break;
            case COURAGE:
                write_line("You are a brave soul.");
                game.car.name="Courage";
                break;
            case JOKER:
                write_line("You are a fun soul.");
                game.car.name="Joker";
                break;
            case FAIRIE:
                write_line("You are a magical soul.");
                game.car.name="Fairie";
                break;
            case DRAGON:
                write_line("You are a powerful soul.");
                game.car.name="Dragon";
                break;
            default:
                write_line("Please choose a valid option from the menu.");
        }
}
void display_header(game_data game)
{
    double fuel_width;
    fuel_width=300*game.car.fuel;
    draw_rectangle(COLOR_LIGHT_BLUE,500,0,500,200,option_to_screen());
    fill_rectangle(COLOR_LIGHT_BLUE,500,0,500,200,option_to_screen());
    draw_text("Points: "+ to_string(game.car.points),COLOR_DARK_BLUE,"display",30,500,10,option_to_screen());
    draw_text("Stars: "+ to_string(game.car.star),COLOR_DARK_BLUE,"display",30,500,40,option_to_screen());
    draw_text("FUEL",COLOR_DARK_BLUE,"display",30,700,15,option_to_screen());
    draw_bitmap("empty",700,50,option_to_screen());
    draw_bitmap("full",700,50,option_part_bmp(0,0,fuel_width,bitmap_height("full"),option_to_screen()));
    draw_text("Character Name: " + game.car.name,COLOR_DARK_BLUE,"display",30,500,90,option_to_screen());
    draw_text("Press 1,2,or 3 to change the car.",COLOR_DARK_BLUE,"display",
    30,500,130,option_to_screen());
}

game_data new_game()
{
    game_data result;
    result.car=start_car();
    return result;
}


void add_obstacle(game_data &game)
{
    if(rnd()<=0.02)
    {
        game.obstacles.push_back(new_obstacle(rnd(SPOT),rnd(LOCATION)));
    }
}


void apply_obstacle(game_data &game)
{
    //Determining the score and name based on the obstacle
    for(int i=0;i<game.obstacles.size();i++)
    {
        switch(game.obstacles[i].obstacle)
        {
            case DANGER:
                game.car.fuel=game.car.fuel*0.5;
                game.car.points-=500;
                game.car.star-=5;
                break;
            case HELMET:
                game.car.fuel=game.car.fuel*1.1;
                game.car.points+=200;
                game.car.star+=2;
                break;
            case TREASURE:
                game.car.fuel=game.car.fuel*1.5;
                game.car.points+=1000;
                game.car.star+=10;
                break;
            case BALLOON:
                game.car.fuel=game.car.fuel*1.25;
                game.car.points+=500;
                game.car.star+=5;
                break;
            default:
                break;
        }
    }
    //Sound effect played when player hits an obstacle
    play_sound_effect("positive");
}


void remove_obstacle(game_data &game,int index)
{
    int last_idx;
    last_idx=game.obstacles.size()-1;
    game.obstacles[index]=game.obstacles[last_idx];
    game.obstacles.pop_back();
}


void check_collisions(game_data &game)
{
    for(int i=game.obstacles.size()-1;i>=0;i--)
    {
        if(sprite_collision(game.car.car_sprite,game.obstacles[i].obstacle_sprite))
        {
            apply_obstacle(game);
            remove_obstacle(game,i);
        }
    }
}


void update_game(game_data &game)
{
    add_obstacle(game);
    check_collisions(game);
    for(int i=0;i<game.obstacles.size();i++)
    {
        update_obstacle(game.obstacles[i]);
    }
    //Perform movement and update the camera
    update_car(game.car);
    
}
/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "rollercoaster.txt");
}


int main()
{
    load_resources();
    
    //Declaring and defining the main variable that contains details about the entire game
    game_data game;
    game=new_game();

    //Calling the Procedure for custom messages
    display_character_message(game);

    //Creates a window
    open_window("Rollercoaster Game",1000,800);

    //Loop keeps running until user exits the game window
    while(not quit_requested() )
    {
        //Sets the time limit for the user to achieve a certain score
        game.counter=1000;
        //Loops through the entire game until the time limit is over
        while(game.counter!=0)
        {
            process_events();
            draw_bitmap("rollercoaster",0,0,option_to_screen());//draw the background image
            input_choices(game.car);//can choose car
            
            //Updates the current state of the car and obstacles
            update_game(game);
            
            //Draws the car after its updated
            draw_car(game.car);

            //Drawing each obstacle after it is updated
            for(int i=0;i<game.obstacles.size();i++)
            {
                draw_obstacle(game.obstacles[i]);
            }

            //Displaying game details
            display_header(game);
            refresh_screen(60);

            //At this point player has won
            if(game.car.points>=5000)
            {
                clear_screen(COLOR_BLACK);
                draw_text("Congratulations you won with "+ to_string(game.counter)+" seconds left",COLOR_WHITE,"display",40,50,400);
                refresh_screen();
                delay(60000);
                close_window("Rollercoaster Game");
            }
            else
            {
                game.counter--;
            }
        }

        //Message displayed when time is over
        clear_screen(COLOR_BLACK);
        draw_text("Oh no! You lost the game.",COLOR_WHITE,"display",40,80,400);
        refresh_screen();
        delay(60000);
    }
        
    return 0;
}
