#pragma once

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Player : public Entity {
protected:
    float speed = 250.f;
    int hp = 3;
    Clock framrate;
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
    void draw() override;
    float getSpeed();
    void move();
    Clock* getFramerate();
    int getHp();
    void decreaseHp(int value = 1);
    void increaseHp(int value = 1);
    int getKeyState();
    void setKeyState(int newValue);
    FloatRect getHitBox();
};