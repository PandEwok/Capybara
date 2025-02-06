#pragma once

#include "Enemy.hpp"
#include "Player.hpp"
#include "Global.hpp"

class Hunter : public Enemy {
private:
    bool isStealthy;
    Player* target;

    Clock animationClock;
public:
    Hunter(Vector2f textureSize, float speed, int hp, bool stealthy, Player* playerTarget);

    void update(float deltaTime) override;
    void setStealthMode(bool stealth);
    Clock& getAnimationClock();
    void draw(RenderTarget& target, RenderStates states) const;

    void setHunterPosition(Vector2f position);
};