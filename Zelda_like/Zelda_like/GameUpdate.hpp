#pragma once

#include "Global.hpp"
#include "Entity.hpp"
#include "Tile.hpp"

extern Player player;
extern vector<shared_ptr<Tile>> tileMap;

class Game {
protected:
	Clock itemClock;
public:
	Game();
	void update();
};