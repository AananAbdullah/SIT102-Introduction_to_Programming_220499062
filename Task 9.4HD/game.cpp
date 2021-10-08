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