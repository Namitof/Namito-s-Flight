#include "raylib.h"

int main()
{
    // Inicialización
    InitWindow(640, 480, "Mi juego");

    int posX = 320;
    int posY = 225;
    float radio = 100.0f;

    // Loop
    while (!WindowShouldClose())
    {
        // Chequeo de Input

        if (IsKeyDown(KEY_UP))
            posY--;

        if (IsKeyDown(KEY_DOWN))
            posY++;

        if (IsKeyDown(KEY_LEFT))
            posX--;

        if (IsKeyDown(KEY_RIGHT))
            posX++;


        // Actualización

        // Dibujado
        BeginDrawing();
        ClearBackground(WHITE); // system("cls");

        DrawCircle(posX, posY, radio, BLUE);

        EndDrawing();
    }

    // Cierre
    CloseWindow();
}