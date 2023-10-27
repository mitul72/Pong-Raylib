#include "game_screen.hpp"
#include "raylib.h"
game_screen::game_screen() {
    main_menu();
}

void game_screen::main_menu() {
    DrawText("Testing", 20, 20, 20,WHITE);
}
