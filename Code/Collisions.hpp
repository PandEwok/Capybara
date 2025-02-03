#pragma once

#include "Global.hpp"
#include "GameUpdate.hpp"

extern vector<shared_ptr<Money>> toDeleteCoins;
extern vector<shared_ptr<Sword>> toDeleteSword;
extern vector<shared_ptr<Axe>> toDeleteAxe;
extern vector<shared_ptr<Dagger>> toDeleteDagger;

void collisionsProcess();