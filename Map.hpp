#pragma once

#include "Global.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Npc.hpp"
#include "GameUpdate.hpp"

class Map {
protected:
	int currentMap = 2;
public:
	enum mapSelection {
		EXTERIOR = 0,
		DUNGEON = 1,
		HOUSE = 2,
		SHOP = 3
	};
	void loadExterior(vector<shared_ptr<Tile>>& tileMap, Player& player);
	void loadDungeon(vector<shared_ptr<Tile>>& tileMap, Player& player);
	void loadHouse(vector<shared_ptr<Tile>>& tileMap, Player& player);
	void loadShop(vector<shared_ptr<Tile>>& tileMap, Player& player);
	int getCurrentMap();
	void setCurrentMap(int value);
};

extern Map map1;