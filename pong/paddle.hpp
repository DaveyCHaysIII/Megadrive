#include "raylib.h"

class Paddle {
public:
    Vector2 position;
    float p_width, p_height;
    float yspeed;
    int up_key, down_key;
    Color color;

    Paddle(float paddle_x_pos, float paddle_y_pos,float width, float height,
           float speed, int up_key, int down_key, Color color)
    : position{ paddle_x_pos, paddle_y_pos },
      p_width(width),
      p_height(height),
      yspeed(speed),
      up_key(up_key),
      down_key(down_key),
      color(color) {}


    void Draw() {
        DrawRectangle(position.x, position.y, p_width, p_height, color);
    }

    void Move() {
        if (IsKeyDown(up_key) && position.y >= 100)
            position.y -= yspeed;
        else if (IsKeyDown(down_key) && position.y <= (700 - p_height))
            position.y += yspeed;
    }
};
