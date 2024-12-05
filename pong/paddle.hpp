#ifndef PADDLE_HPP_
#define PADDLE_HPP_

#include "raylib.h"

class Paddle {
public:
    Vector2 position;
    float p_width, p_height;
    float yspeed;
    int p_up_key, p_down_key;
    Color p_color;
    bool comp_flag;

    void init(float paddle_x_pos, float paddle_y_pos,float paddle_width, float paddle_height,
           float speed, int up_key, int down_key, Color color, bool flag) {
        position.x = paddle_x_pos;
        position.y = paddle_y_pos;
        p_width = paddle_width;
        p_height = paddle_height;
        yspeed = speed;
        p_up_key = up_key;
        p_down_key = down_key;
        p_color = color;
        comp_flag = flag;
    }

    void Draw() {
        DrawRectangle(position.x, position.y, p_width, p_height, p_color);
    }

    void Move() {
        if (IsKeyDown(p_up_key) && position.y >= 100)
            position.y -= yspeed;
        else if (IsKeyDown(p_down_key) && position.y <= (700 - p_height))
            position.y += yspeed;
    }

    void Update(Vector2 ball_pos) {
        // if paddle is computer
        if (comp_flag) {
            if (position.y > ball_pos.y && position.y >= 100)
                position.y -= yspeed;
            else if (position.y < ball_pos.y && position.y <= (700 - p_height))
                position.y += yspeed;
        }
        // if paddle is player
        else {
            if (IsKeyDown(p_up_key) && position.y >= 100)
                position.y -= yspeed;
            else if (IsKeyDown(p_down_key) && position.y <= (700 - p_height))
                position.y += yspeed;
        }
    }
};

#endif // PADDLE_HPP_
