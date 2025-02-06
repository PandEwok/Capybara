#pragma once

#include "Global.hpp"

class Tile {
protected:
	shared_ptr<Sprite> sprite = make_shared<Sprite>();
	string type = "N/A";
	int layer = 0;
public:
	shared_ptr<Sprite> getSprite();
	Tile(Vector2f position);
	string getType();
	void setType(string value);
	int getLayer();
	void setLayer(int value);
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
class Gate : public Tile {
public:
	Gate(Vector2f position);
};

class Bridge : public Tile {
public:
	Bridge(Vector2f position);
};

class House : public Tile {
public:
	House(Vector2f position);
};

class Tree : public Tile {
public:
	Tree(Vector2f position);
};

class Pot : public Tile {
public:
	Pot(Vector2f position);
};

class Flag : public Tile {
public:
	Flag(Vector2f position);
};
