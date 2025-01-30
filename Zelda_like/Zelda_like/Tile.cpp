#include "Tile.hpp"

shared_ptr<Sprite> Tile::getSprite()
{
	return sprite;
}

Tile::Tile(Vector2f position)
{
	sprite->setTextureRect(IntRect(0, 0, 16, 16));
	sprite->setPosition(position);
}

string Tile::getType()
{
	return type;
}

int Tile::getLayer() {
	return layer;
}

Wall::Wall(Vector2f position) : Tile(position) {
	sprite->setTexture(grassWallTopTexture);
	type = "Wall";
}

Floor::Floor(Vector2f position) : Tile(position)
{
	sprite->setTexture(grassTile1Texture);
	type = "Floor";
}

Door::Door(Vector2f position) : Tile(position)
{
	sprite->setTexture(doorExteriorTileTecture);
	type = "Door";
	layer = 1;
}

Bridge::Bridge(Vector2f position) : Tile(position)
{
	sprite->setTexture(bridgeTexture);
	sprite->setTextureRect(IntRect(0, 0, bridgeTexture.getSize().x, bridgeTexture.getSize().y));
	type = "Bridge";
	layer = 1;
}

Tree::Tree(Vector2f position) : Tile(position)
{
	sprite->setTexture(treeTexture);
	sprite->setTextureRect(IntRect(0, 0, treeTexture.getSize().x, treeTexture.getSize().y));
	sprite->setOrigin(Vector2f(16, treeTexture.getSize().y - 16));
	type = "Tree";
	layer = 2;
}

Pot::Pot(Vector2f position) : Tile(position)
{
	sprite->setTexture(potTexture);
	type = "Pot";
}

Gate::Gate(Vector2f position) : Tile(position)
{
	sprite->setTexture(doorExteriorTileTecture);
	sprite->setTextureRect(IntRect(0, 0, doorExteriorTileTecture.getSize().y, doorExteriorTileTecture.getSize().y));
	type = "Gate";
	layer = 1;
}
