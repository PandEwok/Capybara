#include "Hunter.hpp"
#include <cmath>

Hunter::Hunter(Vector2f textureSize, float speed, int hp, bool stealthy, Player* playerTarget)
	: Enemy(textureSize, 10.f, 7), isStealthy(false), target(playerTarget) {
	sprite->setTextureRect(IntRect(0, 0, textureSize.x, textureSize.y));
}

void Hunter::update(float deltaTime) {

	sprite->setTexture(hunterTextureBot);

	if (!target || hp <= 0) return;

	Vector2f playerPosition = target->getPosition();
	Vector2f hunterPosition = getPosition();

	Vector2f direction = playerPosition - hunterPosition;

	float length = sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length != 0) {
		direction /= length;
	}

	sprite->move(direction * speed * deltaTime);

}

void Hunter::setStealthMode(bool stealth) {
	isStealthy = stealth;
}

Clock& Hunter::getAnimationClock() {
	return animationClock;
}

void Hunter::draw(RenderTarget& target, RenderStates states) const {
	target.draw(*sprite, states);
}

void Hunter::setHunterPosition(Vector2f position) {
	sprite->setPosition(position);
}