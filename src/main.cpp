#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <iostream>
#include "raylib.h"
#include "window/raylib_window.hpp"

int main() {

    Window window;
    window.create_window();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
