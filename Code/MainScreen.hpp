#pragma once


#include "Global.hpp"
#include "GameUpdate.hpp"

using namespace std;
using namespace sf;

extern Vector2i mousePosition;
extern bool hoverButtonPlay;


class MainScreen {
public:

	void MainScreenInit();
	void MainScreenUpdate();
	void MainScreenDraw();

};