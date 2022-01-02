#include "raylib.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
Color randomColor(Color color);
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;
    int width = 200;
    int height = 100;
    int x = GetRandomValue(0,screenWidth-width);
    int y = GetRandomValue(0,screenHeight-height);
    int yVelocity = 8;
    int xVelocity = 8;
    Color color = BLUE;
    InitWindow(screenWidth, screenHeight, "sony");
    SetTargetFPS(60);           
    while (!WindowShouldClose())    
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(x,y,width,height,color);
        EndDrawing();
        if(y <= 0 || y >= screenHeight-height){
            yVelocity *= -1;
            color = randomColor(color);
        }
        if(x <= 0 || x >= screenWidth-width){
            xVelocity *= -1;
            color = randomColor(color);
        }
        y += yVelocity;
        x += xVelocity;
    }
    CloseWindow();      
    return 0;
}
Color randomColor(Color color){
    Color colors[] = { DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE,
                       DARKBROWN, GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN,
                       LIGHTGRAY, PINK, YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE};
    Color newColor = colors[GetRandomValue(0,20)];
    return newColor;
}