#include "Item.hpp"

Money::Money(int _amount) : amount(_amount), Entity(Vector2f(rubyTexture.getSize().y, rubyTexture.getSize().y))
{
	sprite->setTexture(rubyTexture);
	sprite->setOrigin(0, 0);
	sprite->setTextureRect(IntRect(0, 0, rubyTexture.getSize().y, rubyTexture.getSize().y));
}

void Money::interact(Player& player)
{
	playerMoney++;
}

//weaponz
Sword::Sword(int _amount) : amount(_amount), Entity(Vector2f(swordTexture.getSize().y, swordTexture.getSize().y))
{
	sprite->setTexture(swordTexture);
	sprite->setOrigin(0, 0);
	sprite->setTextureRect(IntRect(0, 0, swordTexture.getSize().y, swordTexture.getSize().y));
}

void Sword::interact(Player& player)
{
	swordacquired = true;
}

void Sword::swordattack() {
	if (swordacquired == true) {

	}
}

Axe::Axe(int _amount) : amount(_amount), Entity(Vector2f(axeTexture.getSize().y, axeTexture.getSize().y))
{
	sprite->setTexture(axeTexture);
	sprite->setOrigin(0, 0);
	sprite->setTextureRect(IntRect(0, 0, axeTexture.getSize().y, axeTexture.getSize().y));
}

void Axe::interact(Player& player)
{
	axeacquired = true;
}

void Axe::axeattack() {
	if (axeacquired == true) {

	}
}

Dagger::Dagger(int _amount) : amount(_amount), Entity(Vector2f(daggerTexture.getSize().y, daggerTexture.getSize().y))
{
	sprite->setTexture(daggerTexture);
	sprite->setOrigin(0, 0);
	sprite->setTextureRect(IntRect(0, 0, daggerTexture.getSize().y, daggerTexture.getSize().y));
}

void Dagger::interact(Player& player)
{
	daggeracquired = true;
}

void Dagger::daggerattack() {
	if (daggeracquired == true) {

	}
}