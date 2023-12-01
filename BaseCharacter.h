#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    // Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    Vector2 getWorldPos() { return worldPos; }
    virtual void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();
    virtual Vector2 getScreenPos() = 0;
    bool getAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }
    float getHealth() const { return health; }
    virtual void setHealth(float health) { this->health = health; }
    void takeDamage(float damage);
    void setScale(float scale) { this->scale = scale; }
    void setSpeed(float speed) { this->speed = speed; }
protected:
    Texture2D texture{LoadTexture("resources/characters/knight_idle_spritesheet_2.png")};
    Texture2D idle{LoadTexture("resources/characters/knight_idle_spritesheet_2.png")};
    Texture2D run{LoadTexture("resources/characters/knight_run_spritesheet_2.png")};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // direction; 1= right, -1 = left
    float characterDirection = 1.0f;
    // animation
    float runningTime = 0.0f;
    float updateTime = {1.f/12.f}; // how much time til update animation
    int frame = 0; // animation frame from spritesheet
    int maxFrames = 6;
    float speed = 4.0f;
    float scale = 4.0f;
    float width{};
    float height{};
    Vector2 velocity{}; // direction & distance
private:
    bool alive{true};
    float health = {};
};

#endif
