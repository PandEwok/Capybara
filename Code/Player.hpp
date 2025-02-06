#pragma once

#include "Global.hpp"
#include "Entity.hpp"

class Player : public Entity {
protected:
    float speed = 170.f;
    int hp = 3;
    Clock framrate;
    bool isAttacking = false;
    int keyNumber = 0;

public:
    enum direction {
        FRONT = 0,
        BACK = 1,
        RIGHT = 2,
        LEFT = 3
    };

    int facing = FRONT;

    Player();
    float getSpeed();
    void move();
    Clock* getFramerate();
    int getHp();
    void decreaseHp(int value = 1);
    void increaseHp(int value = 1);
    bool getIsAttacking();
    void setIsAttacking(bool value);
    int getKeyState();
    void setKeyState(int newValue);
    FloatRect getHitBox();
    FloatRect getActionRange();
};