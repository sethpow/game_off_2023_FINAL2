#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
    
}

void BaseCharacter::tick(float deltaTime)
{
    // store worldPos last frame
    worldPosLastFrame = worldPos;

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0;
        if (frame > maxFrames) frame = 0;
    }

    // if velocity is 0, dont move
    if (Vector2Length(velocity) != 0.0)  // take vector, return float of how long vector is
    {
        // if x is 1, y is 1, then len of velocity is about 1.414; would move faster diagonally
        // if len of velocity vector is not 0, normalize vector (now has len of 1)
        Vector2 directionNormalized = Vector2Normalize(velocity);
        // know velocity we want to move, need to move map in opposite velocity
            // set worldPos = worldPos - velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(directionNormalized, speed));
        velocity.x < 0.0 ? characterDirection = -1.0 : characterDirection = 1.0; // how many frames shown
        texture = run;
    }
    else texture = idle;
    velocity = { 0.0, 0.0 };

    // draw character
    Rectangle source {frame * width, 0.f, characterDirection * width, height};
    Rectangle dest {getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    Vector2 origin{};
    Color characterColor{255, 255, 255, 255}; // blue, red, yellow, transparency; last color for stealth
    DrawTexturePro(texture, source, dest, origin, 0.f, characterColor);
}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle {
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void BaseCharacter::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0.0)
    {
        health = 0.0;
        setAlive(false);
    }
}
