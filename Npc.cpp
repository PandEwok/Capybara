#include "Npc.hpp"

Npc::Npc(Vector2f position) : Entity(Vector2f(64,32))
{
	sprite->setTexture(shopKeeperTexture);
	sprite->setTextureRect(IntRect(0, 6, 32, 23));
	sprite->setPosition(position + Vector2f(0, -7));
	sprite->setOrigin(Vector2f(16, 13));

	name.setFont(smallFont);
	name.setCharacterSize(8);
	name.setString("Ranga");
	name.setFillColor(Color(50, 212, 0));
	name.setPosition(sprite->getPosition() + Vector2f(-8, -15));
}

void Npc::displayName() {
	name.setPosition(sprite->getPosition() + Vector2f(-15, -17));
	RectangleShape rect(Vector2f(35, 6));
	rect.setFillColor(Color(60, 60, 60));
	rect.setOutlineColor(Color(10, 10, 10));
	rect.setOutlineThickness(1.f);
	rect.setPosition(name.getPosition() + Vector2f(-2, -3));
	window.draw(rect);
	window.draw(name);
}
