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