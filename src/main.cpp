#include <iostream>
#include "raylib.h"
#include "window/raylib_window.hpp"

int main() {

    Window::create_window();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
