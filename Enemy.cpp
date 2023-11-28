#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture, float health)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width/maxFrames;
    height = texture.height;
    speed = 2.0f;
    setHealth(health);
}

void Enemy::tick(float deltaTime)
{
    // Enemy AI
    // find vector from the enemy to the character
    /* AI sudo code
        * Get toTarget
        * Normalize toTarget
        * Multiply toTarget by speed
            * toTarget = toTarget * speed
        * Move Enemy
            * set worldPos
                * worldPos = worldPos + toTarget
    */
    if (!getAlive()) return;
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());

    // check distance to character
    if (Vector2Length(velocity) < radius) velocity = {};

    BaseCharacter::tick(deltaTime);

    // damage player
    if (CheckCollisionRecs(getCollisionRec(), target->getCollisionRec()))
    {
        if (!target->getIsShielded())
        {
            target->takeDamage(dps * deltaTime);
        }
    }
}

Vector2 Enemy::getScreenPos()
{
    // update enemy screenPos
    return Vector2Subtract(worldPos, target->getWorldPos());
}

void Enemy::setTarget(Character* target)
{
    this->target = target;
}

void Enemy::setRadius(float radius)
{
    this->radius = radius;
}
