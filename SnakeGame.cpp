#include<iostream>
using namespace std;
#include<raygui.h>

const int Width = 750;
const int Height = 750;
Color green = { 173 , 205 , 96 , 255 };
Color darkgreen = { 43,51,24,255 };
int cellSize = 30;
int columns = 25;
int rows = 30;

class Food {
public:
    Texture2D texture;
    Food() {
        Image image = LoadImage("apple.png");
        texture = LoadTextureFromImage(image);  // Corrected line to assign the texture
        UnloadImage(image);
    }

    ~Food() {
        UnloadTexture(texture);
    }

    Vector2 position = { 5, 6 };

    void Draw() {
        //DrawTexture(texture, position.x * cellSize, position.y * cellSize,RED);
        DrawTexture(texture,position.x*cellSize,position.y*cellSize,WHITE)
        ;
    }
};

Food food;

void main() {
    cout << "Starting the Game" << endl;
    InitWindow(cellSize * columns, rows * cellSize, "Snake Game");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(green);

        food.Draw();  // Drawing the food here

        EndDrawing();
    }

    CloseWindow();
}
