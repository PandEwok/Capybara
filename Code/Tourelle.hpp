#pragma once 

#include "Enemy.hpp"

class Tourelle : public Enemy {
protected:
	float range;
	float atkSpeed;
	shared_ptr<Sprite>sprite;
public:
	Tourelle(Vector2f textureSize, float speed, int hp, float range, float atkSpeed, shared_ptr<Sprite>sprite);

	float getAtkSpeed() const;
	void setAtkSpeed(float newAtkSpeed);

	float getRange() const;
	void setRange(float newRange);

	shared_ptr<Sprite> getSprite();
};