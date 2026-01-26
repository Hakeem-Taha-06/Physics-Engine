#include <iostream>
#include <raylib.h>
#include <math.h>
#include <chrono>
#include "globals.h"
#include "Entity.h"
#include "Level.h"
#include "UserInterface.h"
#include "Timer.h"

using namespace std;

int main() {
    
    Color Dark_Green = Color{ 20, 160, 133, 255 };

    Level level = Level("");
    UserInterface UI = UserInterface();
    Timer timer = Timer();
   
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    
    float fixedFrameInterval = 1.0f/60.0f;
    float deltaTime = 0;
    int drawCount = 0;
    float accumulator = 0;
    float FPStimer = 0;
    int FPSDisplayValue = 0;

    while (!WindowShouldClose()) {
            
        deltaTime = timer.tick();
        accumulator += deltaTime;
        FPStimer += deltaTime;
        if (accumulator >= fixedFrameInterval) {
            Vector2 mousePos = GetMousePosition();
            bool mousePressed = IsMouseButtonPressed(0);

            if (running) {
                level.update(fixedFrameInterval*timeScale);
            }
            UI.update(mousePos, mousePressed);

            //will move out of here later when i implement an input handler
            if (IsKeyPressed(KEY_SLASH)) timeScale++;
            if (IsKeyPressed(KEY_APOSTROPHE)) timeScale--;

            BeginDrawing();
            ClearBackground(Dark_Green);
            UI.draw();
            level.draw();
            EndDrawing();

            DrawText(TextFormat("FPS = %i", FPSDisplayValue), screenWidth - 200, 50, 40, WHITE);
            drawCount++;
            accumulator -= fixedFrameInterval;
        }
        
        if (FPStimer >= 1.0f) {
            std::cout << "FPS = " << drawCount << std::endl;
            FPSDisplayValue = drawCount;
            FPStimer = 0;
            drawCount = 0;
        }
        
    }

    CloseWindow();
    return 0;
}

