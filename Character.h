#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    void drawShield(bool isShielded);
    bool getIsShielded() { return isShielded; }
    int getShieldDuration() { return shieldDuration; }
    Rectangle getWeaponCollisionRec() { return weaponCollisionRec; }
    float getWeaponDamage() { return dps; }
    void setWeaponDamage(float damage) { dps = damage; }
    int getScore() { return score; }
    void setScore(int score) { this->score = score; }
private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("resources/characters/weapon_axe.png")};
    Rectangle weaponCollisionRec{};
    Vector2 arrowPosition{};
    Vector2 arrowOriginPos{};
    // Vector2 shield{};
    bool isShielded = false;
    float shieldDuration = 100.0;
    float dps = 10.0f;
    int score = 0;
};

#endif
