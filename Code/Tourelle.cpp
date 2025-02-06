#include "Tourelle.hpp"

Tourelle::Tourelle(Vector2f textureSize, float speed, int hp, float range, float atkSpeed, shared_ptr<Sprite>sprite)
	: Enemy(textureSize, speed, hp), atkSpeed(atkSpeed), range(range), sprite(sprite){}

float Tourelle::getAtkSpeed() const {
	return atkSpeed;
}

void Tourelle::setAtkSpeed(float newAtkSpeed) {
	atkSpeed = newAtkSpeed;
}

float Tourelle::getRange() const {
	return range;
}
void Tourelle::setRange(float newRange) {
	range = newRange;
}

shared_ptr<Sprite> Tourelle::getSprite() {
	return sprite;
}