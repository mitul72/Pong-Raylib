#include "raylib.h"
#include "raylib_window.hpp"
#include "game_screen.hpp"
#include "./entities/Player.hpp"
#include <iostream>


Window::Window(){}



    Window::~Window(){
}
    void Window::onWindowResize(){
            ballPosition.x = (ballPosition.x / (float)window_width) * (float)GetScreenWidth();
            ballPosition.y = (ballPosition.y / (float)window_height) * (float)GetScreenHeight();
            p1Position = {(p1Position.x / (float)window_width) * (float)GetScreenWidth(),(p1Position.y / (float)window_height) * (float)GetScreenHeight()};
            p2Position = {(p2Position.x / (float)window_width) * (float)GetScreenWidth(),(p2Position.y / (float)window_height) * (float)GetScreenHeight()};
            window_width = GetScreenWidth();
            window_height = GetScreenHeight();


}
    void Window::create_window(){
        Image icon = LoadImage("./assets/window.png");
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        SetConfigFlags(FLAG_MSAA_4X_HINT);
        InitWindow(window_width, window_height, "Pong");
        SetWindowIcon(icon);

//      SetWindowState(FLAG_VSYNC_HINT);
        SetTargetFPS(60);
        float rect_speed;
        float ball_x_speed = 1;
        float ball_y_speed = 1;
        while (!WindowShouldClose())
        {
            if (IsWindowResized()) {
                onWindowResize();
            }
            game_screen new_game;
            float delta_time = GetFrameTime();
            rect_speed = 500.0f * delta_time;
            if(ball_x_speed > 0)
                ball_x_speed = 400.0f * delta_time;
            else
                ball_x_speed = -400.f * delta_time;
            if(ball_y_speed > 0)
                ball_y_speed = 400.0f * delta_time;
            else
                ball_y_speed = -400.f * delta_time;
            if((ballPosition.x >= p2Position.x -rect_x_offset)&&((p2Position.y<=ballPosition.y&&ballPosition.y<=p2Position.y+rectSize.y))) ball_x_speed*=-1;
            if((ballPosition.x <= p1Position.x + rectSize.x+rect_x_offset)&&((p1Position.y<=ballPosition.y&&ballPosition.y<=p1Position.y+rectSize.y))) ball_x_speed*=-1;
            if(ballPosition.x <= 0 || ballPosition.x >= (float)GetScreenWidth()) ballPosition = { (float)GetScreenWidth()/2, (float)GetScreenHeight()/2 };
            ballPosition.x += ball_x_speed;
            if(ballPosition.y <= 0 || (ballPosition.y + 20)>=(float)GetScreenHeight()) ball_y_speed*=-1;
            ballPosition.y += ball_y_speed;
            if (IsKeyDown(KEY_W)) p1Position.y -= rect_speed;
            if (IsKeyDown(KEY_S)) p1Position.y += rect_speed;

            if (IsKeyDown(KEY_UP)) p2Position.y -= rect_speed;
            if (IsKeyDown(KEY_DOWN)) p2Position.y += rect_speed;

            //Check if player 1 is going out of the boundary
            if (((p1Position.y + rect_height) > window_height)){
                p1Position.y=window_height-rect_height;
            }
            if ((p1Position.y < 0 )){
                  p1Position.y=0;
            }
            if (((p2Position.y + rect_height) > window_height)){
                p2Position.y=window_height-rect_height;
            }
            if ((p2Position.y < 0 )){
                p2Position.y=0;
            }
            Player player1 = Player(p1Position);
            Player player2 = Player(p2Position);



            BeginDrawing();
            ClearBackground(GetColor(0x78a4ab));
            DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), WHITE);
            player1.draw();
            player2.draw();

            DrawCircleLines(GetScreenWidth()/2, GetScreenHeight()/2, 200, WHITE);
            DrawCircleV(ballPosition, 20, WHITE);
            DrawFPS(10,10);
            EndDrawing();
        }
        CloseWindow();

    }

