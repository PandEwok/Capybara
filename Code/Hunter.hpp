#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

class Hunter : public Enemy {
private:
    bool isStealthy;
    Player* target;

public:
    Hunter(Vector2f textureSize, float speed, int hp, bool stealthy, Player* playerTarget, shared_ptr<Texture>texture);

    void update(float deltaTime) override;
    void setStealthMode(bool stealth);
};