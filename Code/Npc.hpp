#pragma once

#include "Global.hpp"
#include "Entity.hpp"

class Npc : public Entity {
protected:
	Text name;
public:
	Clock animationTime;
	Npc(Vector2f position);
	void displayName();
};