#include "Tile.hpp"

shared_ptr<Sprite> Tile::getSprite()
{
	if (sprite != nullptr) {
		return sprite;
	}
}

Tile::Tile(Vector2f position)
{
	sprite->setTextureRect(IntRect(0, 0, 16, 16));
	sprite->setPosition(position);
}

string Tile::getType() {
	return type;
}

void Tile::setType(string value) {
	type = value;
}

int Tile::getLayer() {
	return layer;
}

void Tile::setLayer(int value) {
	layer = value;
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
	sprite->setTexture(doorTileLeftTexture);
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
	sprite->setTexture(doorExteriorTileTexture);
	sprite->setTextureRect(IntRect(0, 0, doorExteriorTileTexture.getSize().y, doorExteriorTileTexture.getSize().y));
	type = "Gate";
	layer = 2;
}

Flag::Flag(Vector2f position) : Tile(position) {
	sprite->setTexture(flagTileTexture);
	type = "Flag";
}

House::House(Vector2f position) : Tile(position)
{
	sprite->setTexture(houseTexture);
	sprite->setTextureRect(IntRect(6, 0, houseTexture.getSize().x - 12, houseTexture.getSize().y));
	sprite->setOrigin(Vector2f(-6, 0));
	type = "Wall";
	layer = 2;
}
