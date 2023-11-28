#include "raylib.h"
#include <stdlib.h>

class Powerup
{
public:
    // Powerup(Vector2 pos, Color color, bool active):
    //     position{pos}, color{color}, active{active} {};
    Powerup(Vector2 pos, Texture2D tex):
        worldPos{pos}, texture{tex} {} // member initializer list
    void Render(Vector2 knightPos);
    Rectangle getCollisionRec(Vector2 knightPos);
    void removePowerup();

    // bool isPlayerTouchingPowerup();
    // Vector2 getPosition() { return position; }
    // Color getColor() { return color; }
    // bool getActive() { return active; }
private:
    Vector2 worldPos{};
    Texture2D texture{};
    float scale = 4.0f;
    // Vector2 position;
    // Color color;
    // bool active;
};
