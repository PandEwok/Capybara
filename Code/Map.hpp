#pragma once

#include "Global.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Tile.hpp"

class Map {
protected:
	int currentMap = 0;
public:
	enum mapSelection {
		EXTERIOR = 0,
		DUNGEON = 1
	};
	void loadExterior(vector<shared_ptr<Tile>>& tileMap, Player& player);
	void loadDungeon(vector<shared_ptr<Tile>>& tileMap, Player& player);
	int getCurrentMap();
	void setCurrentMap(int value);
};

extern Map map1;