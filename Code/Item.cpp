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
