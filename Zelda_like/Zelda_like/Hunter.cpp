#include "Hunter.hpp"
#include <cmath>

Hunter::Hunter(Vector2f textureSize, float speed, int hp, bool stealthy, Player* playerTarget)
	: Enemy(textureSize, speed, hp), isStealthy(false), target(playerTarget) {
}

void Hunter::update(float deltaTime) {
	if (!target) return;
	Vector2f hunterPos = getPosition();
	Vector2f playerPos = target->getPosition();

	Vector2f direction(playerPos.x - hunterPos.x, playerPos.y - hunterPos.y);

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	Vector2f movement(direction.x * getSpeed() * deltaTime, direction.y * getSpeed() * deltaTime);
	move(movement);
}

void Hunter::setStealthMode(bool stealth) {
	isStealthy = stealth;
}