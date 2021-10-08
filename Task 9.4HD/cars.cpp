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
