#pragma once

#include "Global.hpp"
#include "Entity.hpp"
#include "Tile.hpp"

class Map {
public:
	void loadExterior(vector<shared_ptr<Tile>>& tileMap, Player& player);
	void loadDungeon(vector<shared_ptr<Tile>>& tileMap, Player& player);
};

extern Map map1;