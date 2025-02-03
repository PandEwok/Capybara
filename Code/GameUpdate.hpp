#pragma once

#include "Global.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Tile.hpp"

extern Player player;
extern vector<shared_ptr<Tile>> tileMap;
extern vector<shared_ptr<Money>> moneyList;

class Game {
protected:
	Clock itemClock;
public:
	Game();
	void update();
};