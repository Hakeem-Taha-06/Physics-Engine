#include <iostream>
#include <raylib.h>
#include <math.h>
#include <chrono>
#include "globals.h"
#include "Entity.h"
#include "Level.h"
#include "UserInterface.h"

using namespace std;

int main() {
    
    Color Dark_Green = Color{ 20, 160, 133, 255 };

    Level level = Level("");
    UserInterface UI = UserInterface();
   
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    
    long long drawInterval = 1000000000 / FPS;
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto lastTime = std::chrono::high_resolution_clock::now();
    auto timeDifference = currentTime - lastTime;
    long long deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeDifference).count();
    long long accumulator = 0;
    
    int drawCount = 0;
    long long timer = 0;
    int FPSDisplayValue = 0;

    while (!WindowShouldClose()) {
        
        currentTime = std::chrono::high_resolution_clock::now();
        timeDifference = currentTime - lastTime;
        deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeDifference).count();
        accumulator += deltaTime;
        timer += deltaTime;
        lastTime = currentTime;
        
        if (accumulator >= drawInterval) {
            Vector2 mousePos = GetMousePosition();
            bool mousePressed = IsMouseButtonPressed(0);

            if (running) {
                for (int i = 0; i < simSpeed; i++)
                    level.update(deltaTime);
            }
            UI.update(mousePos, mousePressed);

            //will move out of here later when i implement an input handler
            if (IsKeyPressed(KEY_SLASH)) simSpeed++;
            if (IsKeyPressed(KEY_APOSTROPHE)) simSpeed--;
            
            BeginDrawing();
                ClearBackground(Dark_Green);
                UI.draw();
                level.draw();
            EndDrawing();

            DrawText(TextFormat("FPS = %i", FPSDisplayValue), screenWidth - 200, 50, 40, WHITE);
            accumulator -= drawInterval;
            drawCount++;
        }
        if (timer >= 1000000000) {
            std::cout << "FPS = " << drawCount << std::endl;
            std::cout << "deltaTime = " << deltaTime << std::endl;
            std::cout << "accumulator = " << accumulator << std::endl;
            FPSDisplayValue = drawCount;
            timer = 0;
            drawCount = 0;
        }
        
    }

    CloseWindow();
    return 0;
}

