//
// Created by mitul on 2023-10-27.
//

#include "Player.hpp"
#include <stdexcept>

Player::Player(Vector2 player_position) {
    player_dimensions = {player_position.x, player_position.y, rect_width, rect_height};
//    throw std::logic_error("Function not implemented");
}

void Player::update() {
    double delta_time = GetFrameTime();

}
void Player::draw(){
    DrawRectangleRounded(player_dimensions, 10, 0, WHITE);
}
