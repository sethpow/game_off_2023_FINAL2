#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture, float health);
    virtual void tick(float deltaTime) override;
    void setTarget(Character* target);
    virtual Vector2 getScreenPos() override;
    void setRadius(float radius);
private:
    Character* target;
    float dps = 10.0f;
    float radius{};
};

#endif
