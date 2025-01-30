#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

class Hunter : public Enemy {
private:
    bool isStealthy;
    Player* target;

public:
    Hunter(Vector2f textureSize, float speed, int hp, bool stealthy, Player* playerTarget);

    void update(float deltaTime) override;
    void setStealthMode(bool stealth);
};