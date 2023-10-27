#include "raylib.h"

class Player {
    int score = 0;
    const float rect_height = static_cast<float>(GetScreenHeight()/4.0);
    const float rect_width = 20;
    const float rect_x_offset = 10;
    const float rect_speed = 5;
    Rectangle player_dimensions;
public:
    Player(Vector2 player_position);
    void update();

    void draw();
};


