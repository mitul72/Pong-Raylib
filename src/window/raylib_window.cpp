#include "raylib.h"
#include "raylib_window.hpp"
#include "game_screen.hpp"
#include <iostream>

    Window::Window(){}



    Window::~Window(){}
    void Window::create_window(){
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        SetConfigFlags(FLAG_MSAA_4X_HINT);
        InitWindow(1280, 800, "Pong");
//      SetWindowState(FLAG_VSYNC_HINT);
        SetTargetFPS(60);
        const auto rect_height = static_cast<float>(GetScreenHeight()/4.0);
        const float rect_width = 20;
        const float rect_x_offset = 10;
        Vector2 ballPosition = { (float)GetScreenWidth()/2, (float)GetScreenHeight()/2 };
        Vector2 rectSize = {rect_width, rect_height};
        Vector2 p1Position = {rect_x_offset,static_cast<float>((GetScreenHeight()/2.0)-(rect_height/2.0))};
        Vector2 p2Position = {(float)GetScreenWidth()-rect_width-rect_x_offset,static_cast<float>((GetScreenHeight()/2.0)-(rect_height/2.0))};
        float rect_speed;
        float ball_x_speed;
        float ball_y_speed;
        auto screenWidth = (float)GetScreenWidth();
        auto screenHeight = (float)GetScreenHeight();
        while (!WindowShouldClose())
        {
            if (IsWindowResized()) {
                ballPosition.x = (ballPosition.x / (float)screenWidth) * GetScreenWidth();
                ballPosition.y = (ballPosition.y / (float)screenHeight) * GetScreenHeight();
                p1Position = {(p1Position.x / (float)screenWidth) * GetScreenWidth(),(p1Position.y / (float)screenHeight) * GetScreenHeight()};
                p2Position = {(p2Position.x / (float)screenWidth) * GetScreenWidth(),(p2Position.y / (float)screenHeight) * GetScreenHeight()};
                screenWidth = GetScreenWidth();
                screenHeight = GetScreenHeight();
            }


            game_screen new_game;
            double delta_time = GetFrameTime();
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
            if(ballPosition.x <= 0 || ballPosition.x >= GetScreenWidth()) ballPosition = { (float)GetScreenWidth()/2, (float)GetScreenHeight()/2 };
            ballPosition.x += ball_x_speed;
            if(ballPosition.y <= 0 || (ballPosition.y + 20)>=GetScreenHeight()) ball_y_speed*=-1;
            ballPosition.y += ball_y_speed;

            if (IsKeyDown(KEY_UP)) p2Position.y -= rect_speed;
            if (IsKeyDown(KEY_DOWN)) p2Position.y += rect_speed;

            if (IsKeyDown(KEY_W)) p1Position.y -= rect_speed;
            if (IsKeyDown(KEY_S)) p1Position.y += rect_speed;

            BeginDrawing();
            ClearBackground(GetColor(0x78a4ab));
            DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), WHITE);
            DrawRectangleV(p1Position, rectSize, WHITE);
            DrawRectangleV(p2Position, rectSize, WHITE);

            DrawCircleLines(GetScreenWidth()/2, GetScreenHeight()/2, 200, WHITE);
            DrawCircleV(ballPosition, 20, WHITE);
//        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            DrawFPS(10,10);
            EndDrawing();
        }
        CloseWindow();

    }

