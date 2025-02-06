#pragma once

#include "Global.hpp";
#include "Entity.hpp"
#include "Player.hpp"

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

class MarketItem : public Entity, public Item {
protected:
	int price=1;
public:
	MarketItem(int _price = 1);
	int getPrice();
	void setPrice(int value);
};
class DungeonKey : public MarketItem {
public:
	DungeonKey(Vector2f position);
	void interact(Player& player) override;
};


//Weeeeeeeeeeeeeeeeeeeeeeeapons
class Sword : public Entity, public Item {
protected:
	int amount;
public:
	bool swordacquired = false;


	Sword(int _amount = 1);
	void interact(Player& player) override;
	void swordattack();

};

class Axe : public Entity, public Item {
protected:
	int amount;
public:
	bool axeacquired = false;


	Axe(int _amount = 1);
	void interact(Player& player) override;
	void axeattack();

};

class Dagger : public Entity, public Item {
protected:
	int amount;
public:
	bool daggeracquired = false;


	Dagger(int _amount = 1);
	void interact(Player& player) override;
	void daggerattack();

};
