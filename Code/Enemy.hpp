#pragma once

#include "Entity.hpp"

class Enemy : public Entity {
protected:
    float speed;
    int hp;
public:
    Enemy(Vector2f textureSize, float speed, int hp);

    virtual void update(float deltaTime) = 0;

    float getSpeed() const;
    void setSpeed(float newSpeed);

    int getHp() const;
    void setHp(int newHp);
    void decreaseHp(int value = 1);
    bool isDead() const;
};