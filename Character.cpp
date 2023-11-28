#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight):
    windowWidth{winWidth},
    windowHeight{winHeight}
{
    arrowOriginPos = {
        static_cast<float>(winWidth) / 1.95f - scale * (0.5f * width), // minus half of knights width; 6 images on sheet
        static_cast<float>(winHeight) / 1.95f - scale * (0.5f * height)
    };;
    width = texture.width/maxFrames;
    height = texture.height;
    setHealth(100.0f);
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.15f - scale * (0.5f * width), // minus half of knights width; 6 images on sheet
        static_cast<float>(windowHeight) / 2.15f - scale * (0.5f * height)
    };
}

void Character::drawShield(bool isShielded)
{
    this->isShielded = isShielded;

    // draw shield
    if (isShielded)
    {
        float circleRadius = 50.0f;
        Vector2 circlePosition = { getScreenPos().x + width * 1.95f, getScreenPos().y + height * 1.95f };
        Color shieldColor{0, 255, 255, 100}; // blue, red, yellow, transparency
        DrawCircle(circlePosition.x, circlePosition.y, circleRadius, shieldColor);
    }
}

void Character::tick(float deltaTime)
{
    if(!getAlive()) return;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) velocity.y += 1.0;

    BaseCharacter::tick(deltaTime);

    // Draw an arrow from character to cursor
    arrowPosition = GetMousePosition();
    DrawLineEx(arrowOriginPos, arrowPosition, 2.5f, BLANK);

    Vector2 origin{};
    Vector2 offset{};
    float rotation = 0.0f;
    if (characterDirection > 0.f) // facing right
    {
        origin = {0.f, weapon.height * scale}; // bottom left corner
        offset = {40.f, 60.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !getIsShielded() ? 35.f : 0.0f;
    }
    else
    {
        origin = {weapon.width * scale, weapon.height * scale}; // bottom right corner
        offset = {25.f, 60.f};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !getIsShielded() ? -35.f : 0.0f;
        weaponCollisionRec = {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
    }

    // draw sword
    Rectangle source {0.f, 0.f, static_cast<float>(weapon.width) * characterDirection, static_cast<float>(weapon.height)};
    Rectangle dest {getScreenPos().x + offset.x, getScreenPos().y + offset.y, static_cast<float>(weapon.width) * scale, static_cast<float>(weapon.height) * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);

    DrawRectangleLines(
        weaponCollisionRec.x,
        weaponCollisionRec.y,
        weaponCollisionRec.width,
        weaponCollisionRec.height,
        BLANK
    );
}
