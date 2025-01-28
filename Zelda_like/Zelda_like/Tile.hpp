#pragma once

#include "Global.hpp"

class Tile {
protected:
	shared_ptr<Sprite> sprite = make_shared<Sprite>();
	string type;
	int layer = 0;
public:
	shared_ptr<Sprite> getSprite();
	Tile(Vector2f position);
	string getType();
	int getLayer();
};

class Wall : public Tile {
public:
	Wall(Vector2f position);
};

class Floor : public Tile {
public:
	Floor(Vector2f position);
};

class Door : public Tile {
public:
	Door(Vector2f position);
};

class Bridge : public Tile {
public:
	Bridge(Vector2f position);
};

class Tree : public Tile {
public:
	Tree(Vector2f position);
};