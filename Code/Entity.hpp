#pragma once

#include "Global.hpp"
#include <memory>

class Entity {
protected:
	shared_ptr<Sprite> sprite = make_shared<Sprite>();
public:
	Entity(Vector2f textureSize);
	shared_ptr<Sprite> getSprite();

	Vector2f getPosition() const;
};