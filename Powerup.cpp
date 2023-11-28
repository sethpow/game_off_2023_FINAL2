#include "Powerup.h"
#include "raymath.h"

// bool Powerup::isPlayerTouchingPowerup()
// {
//     return CheckCollisionPointCircle(
//         GetMousePosition(),
//         position,
//         30
//     );
// };

void Powerup::Render(Vector2 knightPos)
{
    // subtract knightPos from worldPos; Powerup stays in same place when knight moves
    Vector2 screenPos{ Vector2Subtract(worldPos, knightPos) };
    DrawTextureEx(texture, screenPos, 0.0f, scale, WHITE);
}

Rectangle Powerup::getCollisionRec(Vector2 knightPos)
{
    Vector2 screenPos{ Vector2Subtract(worldPos, knightPos) };
    return Rectangle {
        screenPos.x,
        screenPos.y,
        texture.width * scale,
        texture.height * scale
    };
}

void Powerup::removePowerup()
{
    worldPos = { 0, 0 };
    texture = {};
    scale = 0.0f;
}
