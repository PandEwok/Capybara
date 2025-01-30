#pragma once

#include "Global.hpp";
#include "Entity.hpp"

class Item {
public:
	Clock animationTime;
	virtual void interact(Player& player) = 0;
};

class Money : public Entity, public Item {
protected:
	int amount;
public:
	Money(int _amount = 1);
	void interact(Player& player) override;
};