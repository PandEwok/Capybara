#pragma once

#include "Global.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Npc.hpp"
#include "GameUpdate.hpp"
#include <memory>

class Map {
protected:
	int currentMap = 2;
public:
	enum mapSelection {
		EXTERIOR = 0,
		DUNGEON = 1,
		DUNGEON2 = 4,
		DUNGEON3 = 5,
		HOUSE = 2,
		SHOP = 3
	};
	void loadExterior(vector<shared_ptr<Tile>>& tileMap, Player& player);
	void loadDungeon(vector<shared_ptr<Tile>>& tileMap, Player& player, string floor = "Map/map-dungeon1.txt");
	void loadHouse(vector<shared_ptr<Tile>>& tileMap, Player& player);
	void loadShop(vector<shared_ptr<Tile>>& tileMap, Player& player);
	int getCurrentMap();
	void setCurrentMap(int value);
};

extern Map map1;