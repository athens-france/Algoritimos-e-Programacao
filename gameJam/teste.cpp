#include "raylib.h"

int main() {
    InitWindow(1220, 720, "Meu jogo");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
}

// precisa ter o nome main.cpp para compilar
// gcc -o main.exe main.cpp -Iinclude -Llib -lraylib -lgdi32 -lwinmm