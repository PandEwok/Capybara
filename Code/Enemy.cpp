#include "Enemy.hpp"

Enemy::Enemy(Vector2f textureSize, float speed, int hp) : Entity(textureSize), speed(speed), hp(hp) {}

float Enemy::getSpeed() const {
    return speed;
}

void Enemy::setSpeed(float newSpeed) {
    speed = newSpeed;
}

int Enemy::getHp() const {
    return hp;
}

void Enemy::setHp(int newHp) {
    hp = (newHp < 0) ? 0 : newHp;
}
void Enemy::decreaseHp(int value) {
    hp -= value;
    if (hp < 0) {
        hp = 0;
    }
}

bool Enemy::isDead() const {
    return hp <= 0;
}
