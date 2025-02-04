#pragma once

#include "SFML/Graphics.hpp"
#include "Global.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Tile.hpp"
#include "Hunter.hpp"
#include "Npc.hpp"

extern Player player;
extern vector<shared_ptr<Tile>> tileMap;
extern vector<shared_ptr<Money>> moneyList;
extern vector<shared_ptr<Npc>> npcList;
extern vector<shared_ptr<Sword>> swordad;
extern vector<shared_ptr<Axe>> axead;
extern vector<shared_ptr<Dagger>> daggerad;
extern vector<shared_ptr<Hunter>> hunterad;

class Game {
protected:
	Clock itemClock;
public:
	Game();
	void update();
};
