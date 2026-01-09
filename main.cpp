#include <iostream>
#include <raylib.h>
#include <math.h>
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
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Dark_Green);

        Vector2 mousePos = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(0);

        if (running) {
            for(int i = 0; i < simSpeed; i++)
                level.update();
        }
        UI.update(mousePos, mousePressed);

        //will move out of here later when i implement an input handler
        if (IsKeyPressed(KEY_SLASH)) simSpeed++;
        if (IsKeyPressed(KEY_APOSTROPHE)) simSpeed--;

        UI.draw();
        level.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

